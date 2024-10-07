#pragma once

class Node
{
private:
	double X;
public:
	Node(double x) : X(x) {};
	Node() { X = 0; };
	double GetX() const { return X; }
};
