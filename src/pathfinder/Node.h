#pragma once

#include <memory>
#include <stdint.h>

#define MOVEMENTCOST_STRAIGHT 10
#define MOVEMENTCOST_DIAGONAL 14

class Node {
public:
	Node(uint32_t x, uint32_t y, std::shared_ptr<Node> prev = nullptr, std::shared_ptr<Node> end = nullptr);
	~Node();

	/**
	* @param node the other node
	* @returns whether the nodes have a touchpoint and are located diagonally on the grid
	*/
	bool isDiagonal(Node* node);

	/**
	* @returns the X position of the node on the grid
	*/
	uint32_t getX();

	/**
	* @returns the Y position of the node on the grid
	*/
	uint32_t getY();

	/**
	* recalculates the F score
	* @param recalalcG whether to recalculate the G score before recalculating the F score
	*/
	void calculateFScore(bool recalalcG = true);

	/**
	* recalculates the G score
	*/
	void calculateGScore();

	/**
	* recalculates the H score
	* @param end the end node to find the distance to
	*/
	void calculateHScore(Node* end);

	/**
	* @returns the F position of the node
	*/
	uint32_t getFScore();

	/**
	* @returns the G position of the node
	*/
	uint32_t getGScore();

	/**
	* @returns the H position of the node
	*/
	uint32_t getHScore();
	
	/**
	* set the previous node
	*/
	void setPrevious(std::shared_ptr<Node> previous);

	/**
	* @returns a node closer to the start location
	*/
	std::shared_ptr<Node>& getPrevious();
private:
	uint32_t x, y;
	uint32_t f, g, h;
	std::shared_ptr<Node> prev;
};

