#pragma once

#include <memory>

using namespace std;

class Node {
public:
	Node(int x, int y, shared_ptr<Node> prev = nullptr, shared_ptr<Node> end = nullptr);
	~Node();

	shared_ptr<Node> prev;

	/**
	* @param node the other node
	* @returns whether the nodes have a touchpoint and are located diagonally on the grid
	*/
	bool isDiagonal(Node* node);

	/**
	* @returns the X position of the node on the grid
	*/
	int getX();

	/**
	* @returns the Y position of the node on the grid
	*/
	int getY();

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
	int x, y;
	float f, g, h;
};

