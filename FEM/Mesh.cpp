#include "Mesh.h"
#include <iostream>
void Mesh::Generate(int numberOfElements, double x_start, double x_end)
{
    double length = x_end - x_start;  // ����� ���������
    Nodes.resize(numberOfElements + 1);   // ���������� ����� �� 1 ������, ��� ���������� ���������
    Elements.resize(numberOfElements);    // ���������� ���������

    double h = length / numberOfElements; // ��� (����� ������� ��������)

    // ��������� ����� �� x_start �� x_end
    for (int i = 0; i <= numberOfElements; i++)
    {
        Nodes[i] = Node(x_start + i * h); // ������ ���� �������� ���������� �� x
    }

        // ��������� ���������
    for (int i = 0; i < numberOfElements; i++) 
    {
        Elements[i] = Element(Nodes[i], Nodes[i + 1]); // ������ ������� ��������� ��� ����
    }
}

void Mesh::PrintMesh() const
{
    std::cout << "Nodes:\n";
    for (size_t i = 0; i < Nodes.size(); ++i)
    {
        std::cout << "Node " << i << ": x = " << Nodes[i].GetX() << "\n";
    }

    std::cout << "\nElements:\n";
    for (size_t i = 0; i < Elements.size(); ++i) {
        std::cout << "Element " << i << ": from x = " << Elements[i].Nodes[0].GetX()
                << " to x = " << Elements[i].Nodes[1].GetX() << "\n";
        }
}