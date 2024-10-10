//#include "FiniteElementSolver.h"
//#include "Mesh.h"
//#include <iostream>
//#include "GlobalSystem.h"
//#include <string>
//#include <fstream>
//#include "Equation.h"
//#include <utility>

//
//template<int Degree>
//void FiniteElementSolver<Degree>::GenerateMesh(int numberOfElements, double x_start, double x_end) {
//    mesh = new Mesh<Degree>();
//    mesh->Generate(numberOfElements, x_start, x_end); // Генерация сетки
//}
//
//template<int Degree>
//void FiniteElementSolver<Degree>::AssembleGlobalMatrix()
//{
//    globalSystem = new GlobalSystem(mesh->Nodes.size());
//    for (int i = 0; i < mesh->Elements.size(); i++) {
//        Element<Degree>& element = mesh->Elements[i];
//        element.CalculateStiffnessMatrix(equation);  // Вычисляем матрицу жесткости
//        element.CalculateLoadVector(equation);       // Вычисляем вектор нагрузки
//
//        std::array<int, Degree + 1> nodeIndices;
//        for (int j = 0; j <= Degree; ++j) {
//            nodeIndices[j] = i * Degree + j;  // Пример индексирования узлов
//        }
//        globalSystem->Assemble(element, nodeIndices);
//    }
//}
//template<int Degree>
//void FiniteElementSolver<Degree>::ApplyBoundaryConditions(std::pair<BoundaryConditions, double>& left, std::pair<BoundaryConditions, double>& right)
//{
//    //globalSystem->ApplyBoundaryConditions(0, 10);                              // u(1) = 0
//    //globalSystem->ApplyBoundaryConditions(mesh->Nodes.size() - 1, 1.0);  // u(12) = 1
//    globalSystem->ApplyBoundaryConditions(0, left, equation);                              // u(1) = 0
//    globalSystem->ApplyBoundaryConditions(mesh->Nodes.size() - 1, right, equation);
//}
//
//template<int Degree>
//void FiniteElementSolver<Degree>::SolveSystem() {
//    globalSystem->Solve(); // Решаем глобальную систему
//}
//
//
//
//template<int Degree>
//void FiniteElementSolver<Degree>::PostProcess(const std::string& filename) const {
//    std::ofstream outFile(filename);
//    if (!outFile.is_open())
//    {
//        std::cerr << "Error: Could not open file " << filename << " for writing.\n";
//        return;
//    }
//
//    outFile << "x, u\n";  // Заголовки для удобства
//
//    // Выводим значения узлов и решений
//    for (int i = 0; i < globalSystem->Solution.size(); ++i) {
//
//        outFile << (mesh->Nodes[i].GetX()) << ", " << globalSystem->Solution[i] << "\n";
//    }
//
//    outFile.close();  // Закрываем файл
//    std::cout << "Results have been written to " << filename << "\n";
//}
//template<int Degree>
//FiniteElementSolver<Degree>::~FiniteElementSolver()
//{
//    delete mesh;
//    delete globalSystem;
//}
