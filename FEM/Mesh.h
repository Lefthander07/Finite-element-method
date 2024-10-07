#pragma once
#include "Node.h"
#include "Element.h"
#include <vector>

class Mesh
{
public:
	Mesh() {};
	std::vector<Node> Nodes;
	std::vector<Element> Elements;
	
	void Generate(int numberOfElements, double x_start, double x_end);
	void PrintMesh() const;
};