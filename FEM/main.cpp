#include "FiniteElementSolver.h"
#include "Equation.h"
#include <fstream>
#include <utility>

int main()
{
	int numberOfElements = 40;
	double x_start = -3;
	double x_end = 2;

	std::pair<std::string, double> left;
	std::pair<std::string, double> right;

	left.first = "Neyman";
    left.second = 5;

	right.first = "Dirichlet";
	right.second = 10;

	SecondOrderDifferentialEq equation = SecondOrderDifferentialEq(2, -3, 0, 12);
	FiniteElementSolver solver(equation);

	solver.GenerateMesh(numberOfElements, x_start, x_end); // Генерация сетки
	solver.AssembleGlobalMatrix();                        // Сборка глобальной матрицы
	solver.ApplyBoundaryConditions(left, right);                     // Применение граничных условий
	solver.SolveSystem();                                 // Решение системы
	solver.PostProcess("result.txt");
}