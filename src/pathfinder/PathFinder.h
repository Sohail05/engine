#pragma once

#include "Node.h"

#include <vector>

using namespace std;

struct mapdata {
	int** map;
	size_t width;
	size_t height;
};

struct searchdata {
	vector<Node*>* path;
	vector<Node*>* openList;
	vector<Node*>* closeList;
};

class PathFinder {
public:
	static const int NORMAL = 0;
	static const int START = 1;
	static const int END = 2;
	static const int WALL = 3;

	static const int UNCHECKED = 0;
	static const int CHECKED = 1;

	static searchdata* search(mapdata& map, bool diagonally = true);
	static void release(searchdata* sdata);
private:
	static void addNbors(mapdata& map, mapdata& checkmap, bool diagonally, vector<Node*>* list, Node* parent, Node* end);
	static void addToList(mapdata& map, mapdata& checkmap, vector<Node*>* list, Node* node);
};

