#pragma once

enum class BoundaryConditions
{
	Dirichlet,
	Neyman,
	Robin
};

enum class FormFunction
{
	Linear,
	Cubic
};

class SecondOrderDifferentialEq
{
private:
	double A, B, C, D;
public:
	SecondOrderDifferentialEq(double _A = 0, double _B = 0, double _C = 0, double _D = 0) : A(_A), B(_B), C(_C), D(_D) {};

	double getA() const { return A; }
	double getB() const { return B; }
	double getC() const { return C; }
	double getD() const { return D; }

	void setA(double _A) { A = _A; }
	void setB(double _B) { B = _B; }
	void setC(double _C) { C = _C; }
	void setD(double _D) { D = _D; }

	//method for future lexer and parser;
	void addToA(double _A) { A += _A; }
	void addToB(double _B) { B +=_B; }
	void addToC(double _C) { C += _C; }
	void addtoD(double _D) { D += _D; }
};