#include "Node.h"

#include <math.h>

using namespace std;

Node::Node(uint32_t x, uint32_t y, shared_ptr<Node> prev, shared_ptr<Node> end) : x(x), y(y), f(0), g(0), h(0), prev(prev) {
	if (prev && end) {
		calculateHScore(end.get());
		calculateFScore();
	}
}


Node::~Node() {
}

bool Node::isDiagonal(Node* node) {
	return fabsf(x - node->x) == 1 && fabsf(y - node->y) == 1;
}

uint32_t Node::getX() {
	return x;
}

void Node::calculateFScore(bool recalalcG) {
	if (recalalcG) {
		calculateGScore();
	}
	f = g + h;
}

void Node::calculateGScore() {
	if (isDiagonal(prev.get())) {
		g = prev->g + MOVEMENTCOST_DIAGONAL;
	} else {
		g = prev->g + MOVEMENTCOST_STRAIGHT;
	}
}

void Node::calculateHScore(Node* end) {
	h = fabsf(x - end->x) + fabsf(y - end->y);
}

uint32_t Node::getY() {
	return y;
}

uint32_t Node::getFScore() {
	return f;
}

uint32_t Node::getGScore() {
	return g;
}

uint32_t Node::getHScore() {
	return h;
}

void Node::setPrevious(shared_ptr<Node> previous) {
	this->prev = previous;
}

shared_ptr<Node>& Node::getPrevious() {
	return prev;
}