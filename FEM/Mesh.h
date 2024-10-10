#pragma once
#include "Node.h"
#include "Element.h"
#include <vector>

template<int Degree>
class Mesh
{
public:
	Mesh() {};
	std::vector<Node> Nodes;
	std::vector<Element<Degree>> Elements;
	
	void Generate(int numberOfElements, double x_start, double x_end);
	void PrintMesh() const;
};

#include <iostream>
template<int Degree>
void Mesh<Degree>::Generate(int numberOfElements, double x_start, double x_end)
{
    double length = x_end - x_start;
    int totalNodes = numberOfElements * Degree + 1;
    Nodes.resize(totalNodes);
    Elements.resize(numberOfElements);
    double h = length / numberOfElements;

    for (int i = 0; i < totalNodes; i++)
    {
        Nodes[i] = Node(x_start + (i * h / Degree));
    }


    for (int i = 0; i < numberOfElements; i++)
    {
        std::array<Node, Degree + 1> elementNodes;
        for (int j = 0; j <= Degree; ++j)
        {
            elementNodes[j] = Nodes[i * Degree + j];
        }
        Elements[i] = Element<Degree>(elementNodes);
    }
}

template<int Degree>
void Mesh<Degree>::PrintMesh() const
{
    std::cout << "Nodes:\n";
    for (size_t i = 0; i < Nodes.size(); ++i)
    {
        std::cout << "Node " << i << ": x = " << Nodes[i].GetX() << "\n";
    }

    std::cout << "\nElements:\n";
    for (size_t i = 0; i < Elements.size(); ++i) {
        std::cout << "Element " << i << ": from x = " << Elements[i].Nodes[0].GetX()
            << " to x = " << Elements[i].Nodes[1].GetX() << "\n";
    }
}