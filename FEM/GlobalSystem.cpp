#include "GlobalSystem.h"

GlobalSystem::GlobalSystem(int numberOfNodes)
{
	StiffnessMatrix.resize(numberOfNodes, std::vector<double>(numberOfNodes, 0.0));
	LoadVector.resize(numberOfNodes, 0.0);
	Solution.resize(numberOfNodes, 0.0);
}

void GlobalSystem::Assemble(const Element& element, const std::array<int, 2>& nodeIndices)
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			StiffnessMatrix[nodeIndices[i]][nodeIndices[j]] += element.StiffnessMatrix[i][j];
		}
		LoadVector[nodeIndices[i]] += element.LoadVector[i];
	}
}

void GlobalSystem::ApplyBoundaryConditions(int nodeIndex, std::pair<std::string, double>& condition, SecondOrderDifferentialEq& eq) {
    int n = StiffnessMatrix.size();
    double value = condition.second;

    if (condition.first == "Dirichlet")
    {
        for (int i = 0; i < n; ++i) {
            StiffnessMatrix[nodeIndex][i] = 0.0;
        }
        StiffnessMatrix[nodeIndex][nodeIndex] = 1.0;
        LoadVector[nodeIndex] = value;
    }
    else if (condition.first == "Neyman")
    {
        if (nodeIndex == 0) {
            LoadVector[nodeIndex] += eq.getA() * value;
        }
        else
        {
            LoadVector[nodeIndex] -= eq.getA() * value;
        }
    }
    else if (condition.first == "Robin")
    {
        StiffnessMatrix[nodeIndex][nodeIndex] += 1 * value;
    }
}


/*
void GlobalSystem::Solve() {
    int n = StiffnessMatrix.size();

    // Прямой ход метода Гаусса
    for (int i = 0; i < n; ++i) {
        // Поиск главного элемента
        double maxElement = std::abs(StiffnessMatrix[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (std::abs(StiffnessMatrix[k][i]) > maxElement) {
                maxElement = std::abs(StiffnessMatrix[k][i]);
                maxRow = k;
            }
        }

        // Поменять строки местами
        for (int k = i; k < n; ++k) {
            std::swap(StiffnessMatrix[maxRow][k], StiffnessMatrix[i][k]);
        }
        std::swap(LoadVector[maxRow], LoadVector[i]);

        // Прямой ход для зануления нижней треугольной части
        for (int k = i + 1; k < n; ++k) {
            double factor = StiffnessMatrix[k][i] / StiffnessMatrix[i][i];
            LoadVector[k] -= factor * LoadVector[i];
            for (int j = i; j < n; ++j) {
                StiffnessMatrix[k][j] -= factor * StiffnessMatrix[i][j];
            }
        }
    }

    // Обратный ход метода Гаусса
    for (int i = n - 1; i >= 0; --i) {
        Solution[i] = LoadVector[i] / StiffnessMatrix[i][i];
        for (int k = i - 1; k >= 0; --k) {
            LoadVector[k] -= StiffnessMatrix[k][i] * Solution[i];
        }
    }
}
*/
void thomasAlgorithm(const std::vector<std::vector<double>>& StiffnessMatrix,
    const std::vector<double>& LoadVector,
    std::vector<double>& Solution);

void GlobalSystem::Solve()
{
    thomasAlgorithm(StiffnessMatrix, LoadVector, Solution);
}

//void GlobalSystem::Solve() {
//    int n = StiffnessMatrix.size();
//    for (int j = 0; j < n; j++) {
//        for (int i = j + 1; i < n; i++) {
//            double koef = StiffnessMatrix[i][j] / StiffnessMatrix[j][j];
//            for (int k = j; k < n; k++) {
//                StiffnessMatrix[i][k] -= koef * StiffnessMatrix[j][k];
//            }
//            LoadVector[i] -= koef * LoadVector[j];
//        }
//    }
//    for (int i = n - 1; i >= 0; i--) {
//        double s = 0.0;
//        for (int j = i + 1; j < n; j++) {
//            s += Solution[j] * StiffnessMatrix[i][j];
//        }
//        Solution[i] = (LoadVector[i] - s) / StiffnessMatrix[i][i];
//    }
//}

void GlobalSystem::Print()
{
    int n = StiffnessMatrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << StiffnessMatrix[i][j] << " ";
        }
        std::cout << "||" << LoadVector[i] << "\n";
    }
}


