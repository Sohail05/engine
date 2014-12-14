#pragma once

#include "Node.h"

#include <vector>
#include <memory>

using namespace std;

struct mapdata {

	/**
	* the map
	*/
	int** map;

	/**
	* the width of the map -> map[height][width]
	*/
	size_t width;

	/**
	* the height of the map -> map[height][width]
	*/
	size_t height;
};

class searchdata {
public:
	searchdata(vector<shared_ptr<Node>>* path = nullptr);
	~searchdata();

	/**
	* @returns whether a path was found
	*/
	bool isPathFound();
	vector<shared_ptr<Node>>* getPath();

	/**
	* releases the object
	*/
	void release();
private:

	vector<shared_ptr<Node>>* path;
};

class PathFinder {
public:
	static const int NORMAL = 0;
	static const int START = 1;
	static const int END = 2;
	static const int WALL = 3;

	/**
	* @param map the grid
	* @param diagonally whether the resulting path can go from tile to tile diagonally
	* @returns the shortest path or nullptr if no path was found or two start locations or two end locations were found
	*/
	static searchdata* search(mapdata& map, bool diagonally = true);
	static void release(searchdata* data);
private:
	static const int UNCHECKED = 0;
	static const int CHECKED = 1;

	static void addNbors(mapdata& map, mapdata& checkmap, bool diagonally, vector<shared_ptr<Node>>& list, shared_ptr<Node>& parent, shared_ptr<Node>& end);
	static void addToList(mapdata& map, mapdata& checkmap, vector<shared_ptr<Node>>& list, shared_ptr<Node>& node);
};

