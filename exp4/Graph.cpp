//
// Created by lenovo on 2024/12/3.
//
#include "../Mylab/Graph.h"

// 构造函数
Graph::Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

// 添加边
void Graph::addEdge(int src, int dest) {
    adjList[src].push_back(dest);
    adjList[dest].push_back(src); // 无向图
}

// 广度优先搜索
void Graph::BFS(int start) {
    std::vector<bool> visited(numVertices, false);
    std::queue<int> queue;

    visited[start] = true;
    queue.push(start);

    std::cout << "BFS starting from vertex " << start << ": ";
    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();
        std::cout << vertex << " ";

        for (const int& neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }
    std::cout << std::endl;
}

// 深度优先搜索
void Graph::DFS(int start) {
    std::vector<bool> visited(numVertices, false);
    std::cout << "DFS starting from vertex " << start << ": ";
    DFSUtil(start, visited);
    std::cout << std::endl;
}

void Graph::DFSUtil(int v, std::vector<bool>& visited) {
    visited[v] = true;
    std::cout << v << " ";

    for (const int& neighbor : adjList[v]) {
        if (!visited[neighbor]) {
            DFSUtil(neighbor, visited);
        }
    }
}

// 最短路径（Dijkstra 算法）
void Graph::shortestPath(int start) {
    std::vector<int> dist(numVertices, INT_MAX);
    std::vector<bool> visited(numVertices, false);
    dist[start] = 0;

    for (int count = 0; count < numVertices - 1; ++count) {
        int u = -1;
        for (int i = 0; i < numVertices; ++i) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        visited[u] = true;

        for (const int& neighbor : adjList[u]) {
            if (!visited[neighbor] && dist[u] + 1 < dist[neighbor]) {
                dist[neighbor] = dist[u] + 1;
            }
        }
    }

    std::cout << "Shortest distances from vertex " << start << ": ";
    for (int i = 0; i < numVertices; ++i) {
        std::cout << dist[i] << " ";
    }
    std::cout << std::endl;
}

// 最小生成树（Prim 算法）
void Graph::minimumSpanningTree() {
    std::vector<int> key(numVertices, INT_MAX);
    std::vector<bool> inMST(numVertices, false);
    key[0] = 0;
    int totalWeight = 0;

    for (int count = 0; count < numVertices; ++count) {
        int u = -1;
        for (int i = 0; i < numVertices; ++i) {
            if (!inMST[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        inMST[u] = true;
        totalWeight += key[u];

        for (const int& neighbor : adjList[u]) {
            if (!inMST[neighbor] && 1 < key[neighbor]) { // 假设权重为1
                key[neighbor] = 1;
            }
        }
    }

    std::cout << "Total weight of MST: " << totalWeight << std::endl;
}
