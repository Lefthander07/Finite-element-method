#include "Element.h"
#include "Equation.h"

Element::Element(const Node& node1, const Node& node2)
{
	Nodes[0] = node1;
	Nodes[1] = node2;

	for (int i = 0; i < 2; i++)
	{
		LoadVector[i] = 0.0;
		for (int j = 0; j < 2; j++) {
			StiffnessMatrix[i][j] = 0.0;
		}
	}
}

//void Element::CalculateStiffnessMatrix() {
//	double h = Nodes[1].GetX() - Nodes[0].GetX(); // Длина элемента
//	StiffnessMatrix[0][0] = 1.0 / h + 1; // u
//	StiffnessMatrix[0][1] = -1.0 / h - 1; // v
//	StiffnessMatrix[1][0] = -1.0 / h + 1; // -2v
//	StiffnessMatrix[1][1] = 1.0 / h - 1;  // v
//}

void Element::CalculateStiffnessMatrix(SecondOrderDifferentialEq& eq) {
	double a = eq.getA();
	double b = eq.getB();
	double c = eq.getC();
	double d = eq.getD();

	double h = Nodes[1].GetX() - Nodes[0].GetX(); // Длина элемента
	StiffnessMatrix[0][0] = -(a / h) + (c * h/3) - (b / 2);
	StiffnessMatrix[0][1] = (a / h) + (c * h/6) + (b / 2);
	StiffnessMatrix[1][0] = (a / h) - (c * h/6)  - (b / 2);
	StiffnessMatrix[1][1] = -(a / h) + (c * h/3) + (b / 2);
}


//void Element::CalculateLoadVector() {
//	double h = Nodes[1].GetX() - Nodes[0].GetX(); // Длина элемента
//	LoadVector[0] = -5.0 * h / 2.0; // Нагрузка для u
//	LoadVector[1] = -5.0 * h / 2.0; // Нагрузка для v
//}

void Element::CalculateLoadVector(SecondOrderDifferentialEq& eq) {
	double a = eq.getA();
	double b = eq.getB();
	double c = eq.getC();
	double d = eq.getD();

	double h = Nodes[1].GetX() - Nodes[0].GetX(); // Длина элемента
	LoadVector[0] =   - d * h / 2.0; // Нагрузка для u
	LoadVector[1] =  - d * h / 2.0; // Нагрузка для v
}
