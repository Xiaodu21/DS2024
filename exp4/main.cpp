//
// Created by lenovo on 2024/12/3.
//
#include "../Mylab/Graph.h"
#include <iostream>

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    std::cout << "Testing BFS and DFS:" << std::endl;
    g.BFS(0);
    g.DFS(0);

    std::cout << "\nTesting shortest path:" << std::endl;
    g.shortestPath(0);

    std::cout << "\nTesting minimum spanning tree:" << std::endl;
    g.minimumSpanningTree();

    return 0;
}

