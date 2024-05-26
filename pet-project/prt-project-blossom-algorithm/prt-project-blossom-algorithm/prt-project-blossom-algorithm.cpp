
#include "CGraph.h"


int main(int argc, char* argv[])
{
    int choice;
    std::cout << "Choose input method (1 for adjacency matrix, 2 for edge list): ";
    std::cin >> choice;

    if (choice != 2 && choice != 1)
    {
        std::cout << "Enter a valid number" << std::endl;
        return 0;
    }

    int vertices;
    std::cout << "Enter number of vertices: ";
    std::cin >> vertices;

    CGraph graph(vertices);

    if (choice == 1)
    {
        std::cout << "Enter the adjacency matrix:" << std::endl;
        graph.ReadMatrix(vertices, std::cin);
    }
    else if (choice == 2)
    {
        int edges;
        std::cout << "Enter number of edges: ";
        std::cin >> edges;
        std::cout << "Enter the edges (u v):" << std::endl;
        graph.ReadEdges(vertices, edges, std::cin);
    }

    graph.FindMaximumMatching();

    return 0;
}