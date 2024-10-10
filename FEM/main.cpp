#include "FiniteElementSolver.h"
#include "Equation.h"
#include <fstream>
#include <utility>

int main()
{
	int numberOfElements = 40;
	double x_start = 1;
	double x_end = 12;

	std::pair<BoundaryConditions, double> left;
	std::pair<BoundaryConditions, double> right;

	left.first = BoundaryConditions::Dirichlet;
    left.second = 10;

	right.first = BoundaryConditions::Dirichlet;
	right.second = 1;

	SecondOrderDifferentialEq equation = SecondOrderDifferentialEq(1, 2, 0, -5);
	FiniteElementSolver<3> solver(equation);

	solver.GenerateMesh(numberOfElements, x_start, x_end); //��������� �����
	solver.AssembleGlobalMatrix();                        //������ ���������� �������
	solver.ApplyBoundaryConditions(left, right);          //���������� ��������� �������
	solver.SolveSystem();                                 //������� �������
	solver.PostProcess("result.txt");
}