#pragma once
#include <array>
#include "Node.h"
#include "Equation.h"
class Element
{
public:
	std::array<Node, 2> Nodes; //функция формы линейная
	double StiffnessMatrix[2][2];
	double LoadVector[2];

	Element(const Node& node1, const Node& node2);
	Element() = default;
	void CalculateStiffnessMatrix(SecondOrderDifferentialEq&);
	void CalculateLoadVector(SecondOrderDifferentialEq&);
};
