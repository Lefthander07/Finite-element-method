//#include "Element.h"
//#include "Equation.h"
//
//template<int Degree>
//Element<Degree>::Element(const Node& node1, const Node& node2)
//{
//	Nodes[0] = node1;
//	Nodes[Degree] = node2;
//
//	for (int i = 1; i < Degree; ++i)
//	{
//		Nodes[i] = Node::Interpolate(node1, node2, i / double(Degree));
//	}
//
//	for (int i = 0; i < Degree + 1; ++i) {
//		LoadVector[i] = 0.0;
//		for (int j = 0; j < Degree + 1; ++j) {
//			StiffnessMatrix[i][j] = 0.0;
//		}
//	}
//}
//
//
//template<int Degree>
//Element<Degree>::Element(const std::array<Node, Degree + 1>& elementNodes)
//{
//	Nodes = elementNodes;
//	for (int i = 0; i < Degree + 1; ++i) {
//		LoadVector[i] = 0.0;
//		for (int j = 0; j < Degree + 1; ++j) {
//			StiffnessMatrix[i][j] = 0.0;
//		}
//	}
//}
//
//
//template<int Degree>
//void Element<Degree>::CalculateStiffnessMatrix(SecondOrderDifferentialEq& eq) {
//	double a = eq.getA();
//	double b = eq.getB();
//	double c = eq.getC();
//	double d = eq.getD();
//	double h = Nodes[1].GetX() - Nodes[0].GetX(); // Длина элемента
//	if constexpr (Degree == 1)
//	{
//
//		StiffnessMatrix[0][0] = -(a / h) + (c * h / 3) - (b / 2);
//		StiffnessMatrix[0][1] = (a / h) + (c * h / 6) + (b / 2);
//		StiffnessMatrix[1][0] = (a / h) - (c * h / 6) - (b / 2);
//		StiffnessMatrix[1][1] = -(a / h) + (c * h / 3) + (b / 2);
//	}
//	else if constexpr (Degree == 3)
//	{
//		StiffnessMatrix[0][0];
//		StiffnessMatrix[0][1];
//		StiffnessMatrix[0][2];
//		StiffnessMatrix[0][3];
//			
//		StiffnessMatrix[0][0];
//		StiffnessMatrix[0][1];
//		StiffnessMatrix[0][2];
//			StiffnessMatrix[0][3];
//
//			StiffnessMatrix[0][0];
//			StiffnessMatrix[0][1];
//			StiffnessMatrix[0][2];
//			StiffnessMatrix[0][3];
//			
//			StiffnessMatrix[0][0];
//				StiffnessMatrix[0][1];
//				StiffnessMatrix[0][2];
//				StiffnessMatrix[0][3];
//	}
//}
//
//
//template<int Degree>
//void Element<Degree>::CalculateLoadVector(SecondOrderDifferentialEq& eq) {
//	double a = eq.getA();
//	double b = eq.getB();
//	double c = eq.getC();
//	double d = eq.getD();
//
//	double h = Nodes[1].GetX() - Nodes[0].GetX(); // Длина элемента
//	if constexpr (Degree == 1)
//	{
//		LoadVector[0] = -d * h / 2.0; // Нагрузка для u
//		LoadVector[1] = -d * h / 2.0; // Нагрузка для v
//	}
//	else if constexpr (Degree == 3)
//	{
//		LoadVector[0];
//			LoadVector[0];
//			LoadVector[0];
//			LoadVector[0];
//	}
//}
