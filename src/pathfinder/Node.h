#pragma once

#include <memory>
#include <stdint.h>

class Node {
public:
	Node(int32_t x, int32_t y, std::shared_ptr<Node> prev = nullptr, std::shared_ptr<Node> end = nullptr);
	~Node();

	std::shared_ptr<Node> prev;

	/**
	* @param node the other node
	* @returns whether the nodes have a touchpoint and are located diagonally on the grid
	*/
	bool isDiagonal(Node* node);

	/**
	* @returns the X position of the node on the grid
	*/
	int32_t getX();

	/**
	* @returns the Y position of the node on the grid
	*/
	int32_t getY();

	/**
	* @returns the F position of the node
	*/
	float getFScore();

	/**
	* @returns the G position of the node
	*/
	float getGScore();

	/**
	* @returns the H position of the node
	*/
	float getHScore();
private:
	int32_t x, y;
	float f, g, h;
};

