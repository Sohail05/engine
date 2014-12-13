#include "Node.h"

#include <math.h>

Node::Node(int x, int y, Node* prev, Node* end) : x(x), y(y), f(0), g(0), h(0), prev(prev) {
	if (prev && end) {
		float dx = x - end->x;
		float dy = y - end->y;
		h = sqrtf(dx * dx + dy * dy);
		if (isDiagonal(prev)) {
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