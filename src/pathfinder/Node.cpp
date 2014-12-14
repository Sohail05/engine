#include "Node.h"

#include <math.h>

using namespace std;

Node::Node(int32_t x, int32_t y, shared_ptr<Node> prev, shared_ptr<Node> end) : x(x), y(y), f(0), g(0), h(0), prev(prev) {
	if (prev && end) {
		float dx = x - end->x;
		float dy = y - end->y;
		h = sqrtf(dx * dx + dy * dy);
		if (isDiagonal(prev.get())) {
			g = prev->g + 14;
		} else {
			g = prev->g + 10;
		}
		f = g + h;
	}
}


Node::~Node() {
}

bool Node::isDiagonal(Node* node) {
	return fabsf(x - node->x) == 1 && fabsf(y - node->y) == 1;
}

int32_t Node::getX() {
	return x;
}

int32_t Node::getY() {
	return y;
}

float Node::getFScore() {
	return f;
}

float Node::getGScore() {
	return g;
}

float Node::getHScore() {
	return h;
}