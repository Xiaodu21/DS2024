//
// Created by lenovo on 2024/12/3.
//

#ifndef DS2024A_GRAPH_H
#define DS2024A_GRAPH_H

#endif //DS2024A_GRAPH_H
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <iostream>
#include <climits>

class Graph {
private:
    int numVertices;                      // 顶点数
    std::vector<std::list<int>> adjList; // 邻接表

public:
    Graph(int vertices);                  // 构造函数
    void addEdge(int src, int dest);     // 添加边
    void BFS(int start);                 // 广度优先搜索
    void DFS(int start);                 // 深度优先搜索
    void shortestPath(int start);        // 最短路径（Dijkstra 算法）
    void minimumSpanningTree();          // 最小生成树（Prim 算法）

private:
    void DFSUtil(int v, std::vector<bool>& visited); // 辅助递归函数
};

#endif // GRAPH_H
