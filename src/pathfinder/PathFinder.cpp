#include "PathFinder.hpp"

#include <algorithm>

using namespace std;
using namespace sf;

#define DELETE_MAPDATA(mapdata) \
	for (uint32_t i = 0; i < mapdata.height; i++) \
	{ \
		delete[] mapdata.map[i]; \
	} \
	delete[] mapdata.map;

#define RETURN_NO_PATH return new searchdata

searchdata::searchdata(vector<shared_ptr<Node>>* path, bool excludeUnnecessaryNodes) 
{
	if (path)
	{
		m_nodePath = new vector<Vector2u>;
		m_vectorPath = new vector<Vector2u>;

		for (uint32_t i = 0; i < path->size() - 1; i++) 
		{
			auto node1 = path->at(i);
			auto node2 = path->at(i + 1);

			m_nodePath->push_back(Vector2u(node2->getX(), node2->getY()));
			m_vectorPath->push_back(Vector2u(node2->getX() - node1->getX(), node2->getY() - node1->getY()));
		}

		if (excludeUnnecessaryNodes) 
		{
			for (uint32_t i = 0; i < m_vectorPath->size() - 1; i++)
			{
				auto v1 = m_vectorPath->at(i);
				auto v2 = m_vectorPath->at(i + 1);

				if (v1 == v2)
				{
					m_vectorPath->erase(m_vectorPath->begin() + i);
					m_nodePath->erase(m_nodePath->begin() + i);
				}
			}
		}
	} 
	else 
	{
		m_nodePath = nullptr;
		m_vectorPath = nullptr;
	}
}

searchdata::~searchdata()
{
	delete m_nodePath;
	delete m_vectorPath;
}

bool searchdata::isPathFound()
{
	return m_vectorPath != nullptr;
}

vector<Vector2u>* searchdata::getNodePath()
{ 
	return m_nodePath;
}

vector<Vector2u>* searchdata::getVectorPath()
{
	return m_vectorPath;
}

void searchdata::release() 
{
	delete this; 
}

searchdata* PathFinder::search(mapdata& map, bool excludeUnnecessaryNodes, bool diagonally)
{
	shared_ptr<Node> start = nullptr;
	shared_ptr<Node> end = nullptr;

	for (uint32_t iy = 0; iy < map.height; iy++)
	{
		for (uint32_t ix = 0; ix < map.width; ix++)
		{
			switch (*(int32_t*)(map.map + iy * map.width + ix))
			{
				case START:
					if (start) {
						RETURN_NO_PATH;
					}
					start = make_shared<Node>(ix, iy);
					break;
				case END:
					if (end) {
						RETURN_NO_PATH;
					}
					end = make_shared<Node>(ix, iy);
					break;
			}
		}
	}

	if (!start || !start) 
	{
		RETURN_NO_PATH;
	}

	vector<shared_ptr<Node>> openList;
	vector<shared_ptr<Node>> closeList;
	int32_t** checkmapArray = new int32_t*[map.height];
	for (uint32_t i = 0; i < map.height; i++) 
	{
		checkmapArray[i] = new int32_t[map.width];
	}
	for (uint32_t iy = 0; iy < map.height; iy++) 
	{
		for (uint32_t ix = 0; ix < map.width; ix++)
		{
			checkmapArray[iy][ix] = UNCHECKED;
		}
	}

	mapdata checkmap;
	checkmap.map = checkmapArray;
	checkmap.width = map.width;
	checkmap.height = map.height;

	shared_ptr<Node> parent(new Node(start->getX(), start->getY()));

	while (parent->getX() != end->getX() || parent->getY() != end->getY()) 
	{
		shared_ptr<Node> step = nullptr;
		auto containedNodes = addNbors(map, checkmap, diagonally, openList, parent, end);

		if (openList.size() == 0)
		{
			DELETE_MAPDATA(checkmap);
			RETURN_NO_PATH;
		}

		for (auto node : openList)
		{
			if (!step || node->getFScore() < step->getFScore())
			{
				step = node;
			}
		}
		
		for (auto node : *containedNodes)
		{
			uint32_t g = step->getGScore();

			if (node->isDiagonal(step.get())) 
			{
				g += MOVEMENTCOST_DIAGONAL;
			} 
			else 
			{
				g += MOVEMENTCOST_STRAIGHT;
			}

			if (node->getGScore() < g)
			{
				step = node;
				step->calculateFScore();
			}
		}
		delete containedNodes;


		closeList.push_back(step);
		openList.erase(remove(openList.begin(), openList.end(), step), openList.end());
		parent = step;
	}

	DELETE_MAPDATA(checkmap);

	vector<shared_ptr<Node>>* path = new vector<shared_ptr<Node>>;

	auto n = closeList.back();
	path->push_back(n);
	while (n->getPrevious())
	{
		n = n->getPrevious();
		path->push_back(n);
	}

	//path->pop_back();
	std::reverse(path->begin(), path->end());

	return new searchdata(path, excludeUnnecessaryNodes);
}

vector<shared_ptr<Node>>* PathFinder::addNbors(mapdata& map, mapdata& checkmap, bool diagonally,
											   vector<shared_ptr<Node>>& list, shared_ptr<Node>& parent, shared_ptr<Node>& end) 
{
	uint32_t x = parent->getX();
	uint32_t y = parent->getY();

	auto containedNodes = new vector<shared_ptr<Node>>;

	if (x > 0) 
	{
		shared_ptr<Node> node(new Node(x - 1, y, parent, end));
		auto containedNode = addToList(map, checkmap, list, node);
		if (containedNode)
		{
			containedNodes->push_back(containedNode);
		}
	}
	if (y > 0)
	{
		shared_ptr<Node> node(new Node(x, y - 1, parent, end));
		auto containedNode = addToList(map, checkmap, list, node);
		if (containedNode)
		{
			containedNodes->push_back(containedNode);
		}
	}
	if (x < map.width - 1)
	{
		shared_ptr<Node> node(new Node(x + 1, y, parent, end));
		auto containedNode = addToList(map, checkmap, list, node);
		if (containedNode)
		{
			containedNodes->push_back(containedNode);
		}
	}
	if (y < map.height - 1)
	{
		shared_ptr<Node> node(new Node(x, y + 1, parent, end));
		auto containedNode = addToList(map, checkmap, list, node);
		if (containedNode)
		{
			containedNodes->push_back(containedNode);
		}
	}

	if (diagonally)
	{
		if (x > 0 && y > 0) 
		{
			shared_ptr<Node> node(new Node(x - 1, y - 1, parent, end));
			auto containedNode = addToList(map, checkmap, list, node);
			if (containedNode) 
			{
				containedNodes->push_back(containedNode);
			}
		}
		if (x < map.width - 1 && y < map.height - 1)
		{
			shared_ptr<Node> node(new Node(x + 1, y + 1, parent, end));
			auto containedNode = addToList(map, checkmap, list, node);
			if (containedNode) 
			{
				containedNodes->push_back(containedNode);
			}
		}
		if (x > 0 && y < map.height - 1)
		{
			shared_ptr<Node> node(new Node(x - 1, y + 1, parent, end));
			auto containedNode = addToList(map, checkmap, list, node);
			if (containedNode) 
			{
				containedNodes->push_back(containedNode);
			}
		}
		if (x < map.width - 1 && y > 0) 
		{
			shared_ptr<Node> node(new Node(x + 1, y - 1, parent, end));
			auto containedNode = addToList(map, checkmap, list, node);
			if (containedNode) 
			{
				containedNodes->push_back(containedNode);
			}
		}
	}

	return containedNodes;
}

shared_ptr<Node> PathFinder::addToList(mapdata& map, mapdata& checkmap, vector<shared_ptr<Node>>& list, shared_ptr<Node>& node)
{
	uint32_t x = node->getX();
	uint32_t y = node->getY();

	if (checkmap.map[y][x] == CHECKED) 
	{
		return node;
	}

	int32_t tile = *(int32_t*)(map.map + y * map.width + x);
	if (tile != WALL && tile != START)
	{
		if (checkmap.map[y][x] != CHECKED) 
		{
			checkmap.map[y][x] = CHECKED;
			list.push_back(node);
		}
	}

	return nullptr;
}

void PathFinder::release(searchdata* sdata)
{
	sdata->release();
}
