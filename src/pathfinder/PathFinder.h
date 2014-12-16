#pragma once

#include "Node.h"

#include <vector>
#include <memory>

struct mapdata {

	/**
	* the map
	*/
	int32_t** map;

	/**
	* the width of the map -> map[height][width]
	*/
	uint32_t width;

	/**
	* the height of the map -> map[height][width]
	*/
	uint32_t height;
};

class searchdata {
public:
	searchdata(std::vector<std::shared_ptr<Node>>* path = nullptr);
	~searchdata();

	/**
	* @returns whether a path was found
	*/
	bool isPathFound();
	std::vector<std::shared_ptr<Node>>* getPath();

	/**
	* releases the object
	*/
	void release();
private:
	std::vector<std::shared_ptr<Node>>* path;
};

class PathFinder {
public:
	static const int32_t NORMAL = 0;
	static const int32_t START = 1;
	static const int32_t END = 2;
	static const int32_t WALL = 3;

	/**
	* @param map the grid
	* @param diagonally whether the resulting path can go from tile to tile diagonally
	* @returns the shortest path or nullptr if no path was found or two start locations or two end locations were found
	*/
	static searchdata* search(mapdata& map, bool diagonally = true);
	static void release(searchdata* data);
private:
	static const int32_t UNCHECKED = 0;
	static const int32_t CHECKED = 1;

	static std::vector<std::shared_ptr<Node>>* addNbors(mapdata& map, mapdata& checkmap, bool diagonally, std::vector<std::shared_ptr<Node>>& list, std::shared_ptr<Node>& parent, std::shared_ptr<Node>& end);
	static std::shared_ptr<Node> addToList(mapdata& map, mapdata& checkmap, std::vector<std::shared_ptr<Node>>& list, std::shared_ptr<Node>& node);
};

