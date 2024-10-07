#pragma once
#include "Element.h"
#include <iostream>
#include <vector>

class GlobalSystem
{
public:
	std::vector<std::vector<double>> StiffnessMatrix;
	std::vector<double> LoadVector;
	std::vector<double> Solution;

	GlobalSystem(int numberOfNodes);
	void Assemble(const Element& element, const std::array<int, 2>& nodeIndices);
	void ApplyBoundaryConditions(int nodeIndex, std::pair<std::string, double>& condition, SecondOrderDifferentialEq& eq);
	void Solve();
	void Print();
};
