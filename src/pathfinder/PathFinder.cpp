#include "PathFinder.h"

#include <algorithm>

using namespace std;

#define DELETE_MAPDATA(mapdata) \
	for (int32_t i = 0; i < mapdata.height; i++) { \
		delete[] mapdata.map[i]; \
	} \
	delete[] mapdata.map;

#define RETURN_NO_PATH return new searchdata

searchdata::searchdata(vector<shared_ptr<Node>>* path) : path(path) {
	
}

searchdata::~searchdata() {
	delete path;
}

bool searchdata::isPathFound() {
	return path != nullptr;
}

vector<shared_ptr<Node>>* searchdata::getPath() { 
	return path;
}

void searchdata::release() {
	delete this; 
}

searchdata* PathFinder::search(mapdata& map, bool diagonally) {
	shared_ptr<Node> start = nullptr;
	shared_ptr<Node> end = nullptr;

	for (int32_t iy = 0; iy < map.height; iy++) {
		for (int32_t ix = 0; ix < map.width; ix++) {
			switch ((int32_t)*(map.map + iy * map.width + ix)) {
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

	if (!start || !start) {
		RETURN_NO_PATH;
	}

	vector<shared_ptr<Node>> openList;
	vector<shared_ptr<Node>> closeList;
	int32_t** checkmapArray = new int32_t*[map.height];
	for (int32_t i = 0; i < map.height; i++) {
		checkmapArray[i] = new int32_t[map.width];
	}
	for (int32_t iy = 0; iy < map.height; iy++) {
		for (int32_t ix = 0; ix < map.width; ix++) {
			checkmapArray[iy][ix] = UNCHECKED;
		}
	}

	mapdata checkmap;
	checkmap.map = checkmapArray;
	checkmap.width = map.width;
	checkmap.height = map.height;

	shared_ptr<Node> parent(new Node(start->getX(), start->getY()));

	while (parent->getX() != end->getX() || parent->getY() != end->getY()) {
		shared_ptr<Node> step = nullptr;
		addNbors(map, checkmap, diagonally, openList, parent, end);
		if (openList.size() == 0) {
			DELETE_MAPDATA(checkmap);
			RETURN_NO_PATH;
		}

		for (auto node : openList) {
			if (!step || node->getFScore() < step->getFScore()) {
				step = node;
			}
		}

		closeList.push_back(step);
		openList.erase(remove(openList.begin(), openList.end(), step), openList.end());
		parent = step;
	}

	vector<shared_ptr<Node>>* path = new vector<shared_ptr<Node>>;

	auto n = closeList.back();
	path->push_back(n);
	while (n->prev) {
		n = n->prev;
		path->push_back(n);
	}

	path->pop_back();
	reverse(path->begin(), path->end());

	DELETE_MAPDATA(checkmap);

	return new searchdata(path);
}

void PathFinder::addNbors(mapdata& map, mapdata& checkmap, bool diagonally, vector<shared_ptr<Node>>& list, shared_ptr<Node>& parent, shared_ptr<Node>& end) {
	int32_t x = parent->getX();
	int32_t y = parent->getY();

	if (x > 0) {
		shared_ptr<Node> node(new Node(x - 1, y, parent, end));
		addToList(map, checkmap, list, node);
	}
	if (y > 0) {
		shared_ptr<Node> node(new Node(x, y - 1, parent, end));
		addToList(map, checkmap, list, node);
	}
	if (x < map.width - 1) {
		shared_ptr<Node> node(new Node(x + 1, y, parent, end));
		addToList(map, checkmap, list, node);
	}
	if (y < map.height - 1) {
		shared_ptr<Node> node(new Node(x, y + 1, parent, end));
		addToList(map, checkmap, list, node);
	}

	if (diagonally) {
		if (x > 0 && y > 0) {
			shared_ptr<Node> node(new Node(x - 1, y - 1, parent, end));
			addToList(map, checkmap, list, node);
		}
		if (x < map.width - 1 && y < map.height - 1) {
			shared_ptr<Node> node(new Node(x + 1, y + 1, parent, end));
			addToList(map, checkmap, list, node);
		}
		if (x > 0 && y < map.height - 1) {
			shared_ptr<Node> node(new Node(x - 1, y + 1, parent, end));
			addToList(map, checkmap, list, node);
		}
		if (x < map.width - 1 && y > 0) {
			shared_ptr<Node> node(new Node(x + 1, y - 1, parent, end));
			addToList(map, checkmap, list, node);
		}
	}
}

void PathFinder::addToList(mapdata& map, mapdata& checkmap, vector<shared_ptr<Node>>& list, shared_ptr<Node>& node) {
	int32_t x = node->getX();
	int32_t y = node->getY();
	int32_t tile = (int32_t)*(map.map + y * map.width + x);
	if (tile != WALL && tile != START) {
		if (checkmap.map[y][x] != CHECKED) {
			checkmap.map[y][x] = CHECKED;
			list.push_back(node);
		}
	}
}

void PathFinder::release(searchdata* sdata) {
	sdata->release();
}