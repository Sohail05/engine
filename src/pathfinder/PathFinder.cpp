#include "PathFinder.h"

#include <algorithm>

searchdata* PathFinder::search(mapdata& map, bool diagonally) {
	Node* start = nullptr;
	Node* end = nullptr;

	for (int iy = 0; iy < map.height; iy++) {
		for (int ix = 0; ix < map.width; ix++) {
			switch ((int)*(map.map + iy * map.width + ix)) {
				case START:
					if (start) {
						delete start;
						if (end) delete end;
						return nullptr;
					}
					start = new Node(ix, iy);
					break;
				case END:
					if (end) {
						delete end;
						if (start) delete start;
						return nullptr;
					}
					end = new Node(ix, iy);
					break;
			}
		}
	}

	if (!start) {
		if (end) delete end;
		return nullptr;
	}
	if (!end) {
		if (start) delete start;
		return nullptr;
	}

	vector<Node*>* openList = new vector<Node*>;
	vector<Node*>* closeList = new vector<Node*>;
	int** checkmapArray = new int*[map.height];
	for (int i = 0; i < map.height; i++) {
		checkmapArray[i] = new int[map.width];
		for (int j = 0; j < map.width; j++) {
			checkmapArray[i][j] = UNCHECKED;
		}
	}

	mapdata checkmap;
	checkmap.map = checkmapArray;
	checkmap.width = map.width;
	checkmap.height = map.height;

	Node* parent = new Node(start->x, start->y);

	while (parent->x != end->x || parent->y != end->y) {
		Node* step = nullptr;
		addNbors(map, checkmap, diagonally, openList, parent, end);
		if (openList->size() == 0) return nullptr;
		for (Node* node : *openList) {
			if (!step || node->f < step->f) {
				step = node;
			}
		}

		closeList->push_back(step);
		openList->erase(remove(openList->begin(), openList->end(), step), openList->end());
		parent = step;
	}

	vector<Node*>* path = new vector<Node*>;

	Node* n = closeList->back();
	path->push_back(n);
	while (n->prev) {
		n = n->prev;
		path->push_back(n);
	}

	path->pop_back();
	reverse(path->begin(), path->end());

	searchdata* sdata = new searchdata;
	sdata->path = path;
	sdata->openList = openList;
	sdata->closeList = closeList;

	delete start;

	//for (int i = 0; i < checkmap.height; i++) {
	//	delete[] checkmapArray[i];
	//}
	//delete[] checkmapArray;

	return sdata;
}

void PathFinder::addNbors(mapdata& map, mapdata& checkmap, bool diagonally, vector<Node*>* list, Node* parent, Node* end) {
	if (parent->x > 0) {
		Node* node = new Node(parent->x - 1, parent->y, parent, end);
		addToList(map, checkmap, list, node);
	}
	if (parent->y > 0) {
		Node* node = new Node(parent->x, parent->y - 1, parent, end);
		addToList(map, checkmap, list, node);
	}
	if (parent->x < map.width - 1) {
		Node* node = new Node(parent->x + 1, parent->y, parent, end);
		addToList(map, checkmap, list, node);
	}
	if (parent->y < map.height - 1) {
		Node* node = new Node(parent->x, parent->y + 1, parent, end);
		addToList(map, checkmap, list, node);
	}

	if (diagonally) {
		if (parent->x > 0 && parent->y > 0) {
			Node* node = new Node(parent->x - 1, parent->y - 1, parent, end);
			addToList(map, checkmap, list, node);
		}
		if (parent->x < map.width - 1 && parent->y < map.height - 1) {
			Node* node = new Node(parent->x + 1, parent->y + 1, parent, end);
			addToList(map, checkmap, list, node);
		}
		if (parent->x > 0 && parent->y < map.height - 1) {
			Node* node = new Node(parent->x - 1, parent->y + 1, parent, end);
			addToList(map, checkmap, list, node);
		}
		if (parent->x < map.width - 1 && parent->y > 0) {
			Node* node = new Node(parent->x + 1, parent->y - 1, parent, end);
			addToList(map, checkmap, list, node);
		}
	}
}

void PathFinder::addToList(mapdata& map, mapdata& checkmap, vector<Node*>* list, Node* node) {
	int tile = (int)*(map.map + node->y * map.width + node->x);
	if (tile != WALL && tile != START) {
		int** tileptr = checkmap.map + node->y * checkmap.width + node->x;
		if ((int)*tileptr != CHECKED) {
			*tileptr = (int*)CHECKED;
			list->push_back(node);
		}
	}
}

void PathFinder::release(searchdata* sdata) {
	if (sdata->path) {
		for (Node* node : *sdata->path) {
			delete node;
		}
		delete sdata->path;
	}
	if (sdata->openList) {
		for (Node* node : *sdata->openList) {
			delete node;
		}
		delete sdata->openList;
	}
	//if (sdata->closeList) {
	//	for (Node* node : *sdata->closeList) {
	//		delete node;
	//	}
	//	delete sdata->closeList;
	//}
	delete sdata->closeList;
	delete sdata;
}