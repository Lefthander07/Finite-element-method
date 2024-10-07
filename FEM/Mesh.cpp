#include "Mesh.h"
#include <iostream>
void Mesh::Generate(int numberOfElements, double x_start, double x_end)
{
    double length = x_end - x_start;  // Длина интервала
    Nodes.resize(numberOfElements + 1);   // Количество узлов на 1 больше, чем количество элементов
    Elements.resize(numberOfElements);    // Количество элементов

    double h = length / numberOfElements; // Шаг (длина каждого элемента)

    // Генерация узлов от x_start до x_end
    for (int i = 0; i <= numberOfElements; i++)
    {
        Nodes[i] = Node(x_start + i * h); // Каждый узел получает координату по x
    }

        // Генерация элементов
    for (int i = 0; i < numberOfElements; i++) 
    {
        Elements[i] = Element(Nodes[i], Nodes[i + 1]); // Каждый элемент связывает два узла
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