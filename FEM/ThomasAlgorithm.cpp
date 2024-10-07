#include <vector>

void thomasAlgorithm(const std::vector<std::vector<double>>& StiffnessMatrix,
    const std::vector<double>& LoadVector,
    std::vector<double>& Solution)
{
    int n = StiffnessMatrix.size();

    std::vector<double> a(n, 0.0); // ������������
    std::vector<double> b(n, 0.0); // ���������
    std::vector<double> c(n, 0.0); // ������������

    // ��������� ������������ (a), ��������� (b), ������������ (c)
    for (int i = 0; i < n; ++i) {
        b[i] = StiffnessMatrix[i][i]; // ���������

        if (i > 0) {
            a[i] = StiffnessMatrix[i][i - 1]; // ������������
        }

        if (i < n - 1) {
            c[i] = StiffnessMatrix[i][i + 1]; // ������������
        }
    }

    // ������ ��� ��������
    std::vector<double> c_star(n, 0.0);
    std::vector<double> d_star(n, 0.0);

    // ����������� ������������� ��� ������ ������
    c_star[0] = c[0] / b[0];
    d_star[0] = LoadVector[0] / b[0];

    for (int i = 1; i < n; ++i) {
        double m = b[i] - a[i] * c_star[i - 1];
        c_star[i] = c[i] / m;
        d_star[i] = (LoadVector[i] - a[i] * d_star[i - 1]) / m;
    }

    // �������� ��� ��������
    Solution[n - 1] = d_star[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        Solution[i] = d_star[i] - c_star[i] * Solution[i + 1];
    }
}