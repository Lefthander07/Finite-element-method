#pragma once

class Node
{
private:
	double X;
public:
	Node(double x) : X(x) {};
	Node() { X = 0; };
	double GetX() const { return X; }
	static Node Interpolate(const Node& node1, const Node& node2, double t)	{ double x = node1.GetX() + t * (node2.GetX() - node1.GetX()); return Node(x); }
};
