#pragma once
#include <iostream>

class CGraph
{
public:
    CGraph();
    CGraph(int vertexes);
    CGraph(const CGraph& src);
    ~CGraph();
    void PrintMatrix();
    void ReadMatrix(int vertexes, std::istream& stream);
    void ReadEdges(int vertexes, int edges, std::istream& stream);
    void FindMaximumMatching();

private:
    void init();
    void initMatrix();
    void dispose();
    void disposeMatrix();
    int lca(int u, int v);
    void markPath(int u, int b);
    int findPath(int root);
    void augmentPath(int u);
    void initArrays();
    void processQueue(int root);
    bool processEdge(int u, int v, int root);

    int _vertexes;
    int** _matrix;
    int* parent;
    int* base;
    bool* blossom;
    int* match;
    int* queue;
    int front;
    int back;
    bool* inQueue;
};

