#include <iostream>
#include "CGraph.h"

CGraph::CGraph() : _vertexes(0), _matrix(nullptr), parent(nullptr), base(nullptr), blossom(nullptr), match(nullptr), queue(nullptr), inQueue(nullptr) {}

CGraph::CGraph(int vertexes) : _vertexes(vertexes), _matrix(nullptr), parent(nullptr), base(nullptr), blossom(nullptr), match(nullptr), queue(nullptr), inQueue(nullptr)
{
    init();
}
CGraph::CGraph(const CGraph& src) : _vertexes(src._vertexes)
{

    initMatrix();
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            _matrix[i][j] = src._matrix[i][j];
        }
    }

    parent = new int[_vertexes];
    base = new int[_vertexes];
    blossom = new bool[_vertexes];
    match = new int[_vertexes];
    queue = new int[_vertexes];
    inQueue = new bool[_vertexes];

    for (int i = 0; i < _vertexes; ++i)
    {
        parent[i] = src.parent[i];
        base[i] = src.base[i];
        blossom[i] = src.blossom[i];
        match[i] = src.match[i];
        queue[i] = src.queue[i];
        inQueue[i] = src.inQueue[i];
    }

    front = src.front;
    back = src.back;
}

CGraph::~CGraph()
{
    dispose();
}

void CGraph::PrintMatrix()
{
    if (_matrix == nullptr)
    {
        std::cout << "Graph empty" << std::endl;
        return;
    }

    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            std::cout << _matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void CGraph::ReadMatrix(int vertexes, std::istream& stream)
{
    _vertexes = vertexes;
    initMatrix();
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            stream >> _matrix[i][j];
        }
    }
}

void CGraph::ReadEdges(int vertexes, int edges, std::istream& stream)
{
    _vertexes = vertexes;
    initMatrix();
    for (int i = 0; i < _vertexes; ++i)
    {
        for (int j = 0; j < _vertexes; ++j)
        {
            _matrix[i][j] = 0;
        }
    }
    int u, v;
    for (int i = 0; i < edges; ++i)
    {
        stream >> u >> v;
        u--; v--;
        _matrix[u][v] = 1;
        _matrix[v][u] = 1;
    }
}

void CGraph::init()
{
    dispose();
    initMatrix();
    parent = new int[_vertexes];
    base = new int[_vertexes];
    blossom = new bool[_vertexes];
    match = new int[_vertexes];
    queue = new int[_vertexes];
    inQueue = new bool[_vertexes];
}

void CGraph::initMatrix()
{
    if (_vertexes == 0)
    {
        return;
    }
    _matrix = new int* [_vertexes];
    for (int i = 0; i < _vertexes; ++i)
    {
        _matrix[i] = new int[_vertexes] {0};
    }
}

void CGraph::dispose()
{
    disposeMatrix();
    delete[] parent;
    delete[] base;
    delete[] blossom;
    delete[] match;
    delete[] queue;
    delete[] inQueue;
}

void CGraph::disposeMatrix()
{
    if (_matrix != nullptr)
    {
        for (int i = 0; i < _vertexes; ++i)
        {
            delete[] _matrix[i];
        }
        delete[] _matrix;
        _matrix = nullptr;
    }
}

// Вспомогательные функции для алгоритма Blossom
int CGraph::lca(int u, int v)
{
    bool* visited = new bool[_vertexes]();
    while (true)
    {
        u = base[u];
        visited[u] = true;
        if (match[u] == -1)
        {
            break;
        }
        u = parent[match[u]];
    }
    while (true)
    {
        v = base[v];
        if (visited[v])
        {
            delete[] visited;
            return v;
        }
        v = parent[match[v]];
    }
}

void CGraph::markPath(int u, int b)
{
    while (base[u] != b)
    {
        blossom[base[u]] = true;
        blossom[base[match[u]]] = true;
        u = parent[match[u]];
        if (base[u] != b)
        {
            parent[u] = match[u];
        }
    }
}

int CGraph::findPath(int root)
{
    front = 0;
    back = 0;

    initArrays();
    processQueue(root);

    return 0;
}

void CGraph::augmentPath(int u)
{
    while (u != -1)
    {
        int pv = parent[u];
        int ppv = match[pv];
        match[u] = pv;
        match[pv] = u;
        u = ppv;
    }
}

void CGraph::initArrays()
{
    for (int i = 0; i < _vertexes; ++i)
    {
        parent[i] = -1;
        base[i] = i;
        inQueue[i] = false;
    }
}

void CGraph::processQueue(int root)
{
    queue[back++] = root;  // Добавляем корневую вершину в очередь
    inQueue[root] = true;


    while (front < back)
    {
        int u = queue[front++];

        for (int v = 0; v < _vertexes; ++v)
        {
            if (_matrix[u][v] && base[u] != base[v] && match[u] != v)
            {
                if (processEdge(u, v, root))
                {
                    return;
                }
            }
        }
    }
}

bool CGraph::processEdge(int u, int v, int root)
{
    if ((v == root) || (match[v] != -1 && parent[match[v]] != -1))
    {
        int b = lca(u, v);
        for (int i = 0; i < _vertexes; ++i)
        {
            blossom[i] = false;
        }

        markPath(u, b);
        markPath(v, b);

        for (int i = 0; i < _vertexes; ++i)
        {
            if (blossom[base[i]])
            {
                base[i] = b;

                if (!inQueue[i])
                {
                    queue[back++] = i;
                    inQueue[i] = true;
                }
            }
        }
    }
    else if (parent[v] == -1)
    {
        parent[v] = u;
        if (match[v] == -1)
        {
            augmentPath(v);
            return true;
        }
        else
        {
            queue[back++] = match[v];
            inQueue[match[v]] = true;
        }
    }
    return false;
}

void CGraph::FindMaximumMatching()
{


    for (int i = 0; i < _vertexes; ++i)
    {
        match[i] = -1;
    }

    for (int i = 0; i < _vertexes; ++i)
    {
        if (match[i] == -1)
        {
            findPath(i);
        }
    }

    std::cout << std::endl << "Maximum matching:" << std::endl;
    for (int i = 0; i < _vertexes; ++i)
    {
        if (match[i] != -1 && i < match[i])
        {
            std::cout << i + 1 << " - " << match[i] + 1 << std::endl;
        }
    }
}
