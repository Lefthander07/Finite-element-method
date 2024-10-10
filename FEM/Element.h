#pragma once
#include <array>
#include "Node.h"
#include "Equation.h"
#include <iostream>
template<int Degree>
class Element
{
public:
	static constexpr int NumNodes = Degree + 1;
	std::array<Node, NumNodes> Nodes;
	double StiffnessMatrix[NumNodes][NumNodes];
	double LoadVector[NumNodes];

	Element(const Node& node1, const Node& node2);
	Element(const std::array<Node, Degree + 1>& elementNodes);
	Element() = default;
	void CalculateStiffnessMatrix(SecondOrderDifferentialEq&);
	void CalculateLoadVector(SecondOrderDifferentialEq&);
};


template<int Degree>
Element<Degree>::Element(const Node& node1, const Node& node2)
{
	Nodes[0] = node1;
	Nodes[Degree] = node2;

	for (int i = 1; i < Degree; ++i)
	{
		Nodes[i] = Node::Interpolate(node1, node2, i / double(Degree));
	}

	for (int i = 0; i < Degree + 1; ++i) {
		LoadVector[i] = 0.0;
		for (int j = 0; j < Degree + 1; ++j) {
			StiffnessMatrix[i][j] = 0.0;
		}
	}
}


template<int Degree>
Element<Degree>::Element(const std::array<Node, Degree + 1>& elementNodes)
{
	Nodes = elementNodes;
	for (int i = 0; i < Degree + 1; ++i) {
		LoadVector[i] = 0.0;
		for (int j = 0; j < Degree + 1; ++j) {
			StiffnessMatrix[i][j] = 0.0;
		}
	}
}


template<int Degree>
void Element<Degree>::CalculateStiffnessMatrix(SecondOrderDifferentialEq& eq) {
	double a = eq.getA();
	double b = eq.getB();
	double c = eq.getC();
	double d = eq.getD();
	double h = Nodes[Degree].GetX() - Nodes[0].GetX(); // Длина элемента
	if constexpr (Degree == 1)
	{

		StiffnessMatrix[0][0] = -(a / h) + (c * h / 3.0) - (b / 2);
		StiffnessMatrix[0][1] = (a / h) + (c * h / 6.0) + (b / 2);
		StiffnessMatrix[1][0] = (a / h) - (c * h / 6.0) - (b / 2);
		StiffnessMatrix[1][1] = -(a / h) + (c * h / 3.0) + (b / 2);
	}
	else if constexpr (Degree == 3)
	{
		StiffnessMatrix[0][0] = - 37 * a / (10 * h) + (-1.0/2.0) * b + c * (8 * h /105);
		StiffnessMatrix[0][1] = 189 * a / (40 * h) + (57.0/80.0) * b + c * (33 * h / 560);
		StiffnessMatrix[0][2] = -27 * a / (20 * h) + (-3.0/10.0) * b + c * (-3 * h / 140);
		StiffnessMatrix[0][3] = 13 * a / (40 * h) + (7.0 / 80.0) * b + c * (19 * h / 1680);

		StiffnessMatrix[1][0] = 189 * a / (40 * h) + (-57.0/80.0) * b + c * (33 * h / 5605);
		StiffnessMatrix[1][1] = -54 * a / (5 * h) + 0 * b + c * (27 * h / 70);
		StiffnessMatrix[1][2] = 297 * a / (40 * h) + (81.0/80.0) * b + c * (-27 * h / 560);
		StiffnessMatrix[1][3] = -27 * a / (20 * h) + (-3.0/10.0) * b + c * (-3 * h / 140);

		StiffnessMatrix[2][0] = -27 * a / (20 * h) + (3.0/10.0) * b + c * (-3 * h / 140);
		StiffnessMatrix[2][1] = 297 * a / (40 * h) + (-81.0/80.0)*b + c * (-27 * h / 560);
		StiffnessMatrix[2][2] = -54 * a / (5 * h) + 0 * b + c * (27 * h / 70);
		StiffnessMatrix[2][3] = 189 * a/ (40 * h) + (57.0/80.0)*b + c * (33 * h / 560);

		StiffnessMatrix[3][0] = 13 * a / (40 * h) + (-7.0/80.0) * b + c * (19 * h / 1680);
		StiffnessMatrix[3][1] = -27 * a / (20 * h) + (3.0/10.0) * b + c * (-3 * h / 140);
		StiffnessMatrix[3][2] = 189 * a / (40 * h) + (-57.0/80.0) * b + c * (33 * h / 560);
		StiffnessMatrix[3][3] = -37 * a / (10 * h) + (1.0/ 2.0) * b + c * (8 * h / 105);

		//StiffnessMatrix[0][0] += -a * 37 / (10 * h) - b / 2. + c * 8 * h / 105.;
		//StiffnessMatrix[0][1] += a * 189 / (40 * h) + b * 57 / 80. + c * 33 * h / 560.;
		//StiffnessMatrix[0][2] += -a * 27 / (20 * h) - b * 3 / 10. - c * 3 * h / 140.;
		//StiffnessMatrix[0][3] += a * 13 / (40 * h) + b * 7 / 80. + c * 19 * h / 1680.;

		//StiffnessMatrix[1][0] += a * 189 / (40 * h) - b * 57 / 80. + c * 33 * h / 560.;
		//StiffnessMatrix[1][1] += -a * 54 / (5 * h) + c * 27 * h / 70.;
		//StiffnessMatrix[1][2] += a * 297 / (40 * h) + b * 81 / 80. - c * 27 * h / 560.;
		//StiffnessMatrix[1][3] += -a * 27 / (20 * h) - b * 3 / 10. - c * 3 * h / 140.;

		//StiffnessMatrix[2][0] += -a * 27 / (20 * h) + b * 3 / 10. - c * 3 * h / 140.;
		//StiffnessMatrix[2][1] += a * 297 / (40 * h) - b * 81 / 80. - c * 27 * h / 560.;
		//StiffnessMatrix[2][2] += -a * 54 / (5 * h) + c * 27 * h / 70.;
		//StiffnessMatrix[2][3] += a * 189 / (40 * h) + b * 57 / 80. + c * 33 * h / 560.;

		//StiffnessMatrix[3][0] += a * 13 / (40 * h) - b * 7 / 80. + c * 19 * h / 1680.;
		//StiffnessMatrix[3][1] = -27 * a / (20 * h) + (3.0 / 10.0) * b + c * (-3 * h / 140);
		//StiffnessMatrix[3][2] += a * 189 / (40 * h) - b * 57 / 80. - c * 3 * h / 140.;
		//StiffnessMatrix[3][3] += -a * 37 / (10 * h) + b / 2. + c * 8 * h / 105.;
	}
}


template<int Degree>
void Element<Degree>::CalculateLoadVector(SecondOrderDifferentialEq& eq) {
	double a = eq.getA();
	double b = eq.getB();
	double c = eq.getC();
	double d = eq.getD();

	double h = Nodes[Degree].GetX() - Nodes[0].GetX(); // Длина элемента
	if constexpr (Degree == 1)
	{
		LoadVector[0] = -d * h / 2.0; // Нагрузка для u
		LoadVector[1] = -d * h / 2.0; // Нагрузка для v
	}
	else if constexpr (Degree == 3)
	{
		LoadVector[0] = -d * h / 8.;
		LoadVector[1] = -d * 3 * h / 8.;
		LoadVector[2] = -d * 3 * h / 8.;
		LoadVector[3] = -d * h / 8.;
	}
}
