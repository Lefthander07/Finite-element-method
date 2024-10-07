#pragma once

#include <string>
#include "Mesh.h"
#include "GlobalSystem.h"
#include "Equation.h"
#include <utility>
class FiniteElementSolver
{
public:
	Mesh* mesh;
	GlobalSystem* globalSystem;
	SecondOrderDifferentialEq equation;
public:
	FiniteElementSolver(SecondOrderDifferentialEq& eq) : mesh(nullptr), globalSystem(nullptr), equation(eq) {}
	void GenerateMesh(int numberOfElements, double x_start, double x_end);
	void AssembleGlobalMatrix();
	void ApplyBoundaryConditions(std::pair<std::string, double>&, std::pair<std::string, double>&);
	void SolveSystem();
	void PostProcess(const std::string& filename) const;
	~FiniteElementSolver();
};
