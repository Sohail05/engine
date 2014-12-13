#pragma once
class Node {
public:
	Node(int x, int y, Node* prev = nullptr, Node* end = nullptr);
	~Node();

	int x, y;
	float f, g, h;

	Node* prev;

	bool isDiagonal(Node* node);
};

