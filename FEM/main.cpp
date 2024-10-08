#include "FiniteElementSolver.h"
#include "Equation.h"
#include <fstream>
#include <utility>

int main()
{
	int numberOfElements = 40;
	double x_start = -3;
	double x_end = 2;

	std::pair<BoundaryConditions, double> left;
	std::pair<BoundaryConditions, double> right;

	left.first = BoundaryConditions::Neyman;
    left.second = 5;

	right.first = BoundaryConditions::Dirichlet;
	right.second = 10;

	SecondOrderDifferentialEq equation = SecondOrderDifferentialEq(2, -3, 0, 12);
	FiniteElementSolver solver(equation);

	solver.GenerateMesh(numberOfElements, x_start, x_end); // ��������� �����
	solver.AssembleGlobalMatrix();                        // ������ ���������� �������
	solver.ApplyBoundaryConditions(left, right);                     // ���������� ��������� �������
	solver.SolveSystem();                                 // ������� �������
	solver.PostProcess("result.txt");
}