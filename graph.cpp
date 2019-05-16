#include "graph.hpp"
#include <functional>
#include <unordered_set>
#include <stdio.h>

bool Graph::compare(E_Struct a, E_Struct b)
{
    if (a.edge == b.edge)
    {
        return a.node1 < b.node1;
    }
        return a.edge < b.edge;
}


void Graph::addEdge(int v1, int v2, int ec)
{
    E_Struct tmp;
    tmp.node1 = v1;
    tmp.node2 = v2;
    tmp.edge = ec;
    G.push_back(tmp);
}

void Graph::sort()
{
    std::sort(G.begin(), G.end(), [this](auto l, auto r) {return compare(l, r); });
}

void Graph::Union(int vertex1, int vertex2)
{
    int par = V[vertex2-1].parent;
    for (auto &ii : V)
    {
        if (ii.parent == par) { ii.parent = V[vertex1-1].parent; }
    }
}

void Graph::makeClusters()
{
    for (int ii = 1; ii <= Graph::NodeCount; ii++)
    {
        cluster tmp;
        tmp.vertix = ii;
        tmp.parent = ii;
        V.push_back(tmp);
    }
}

int Graph::find(int vertex)
{
    return (V[vertex-1].parent);
}

int Graph::nodeCount()
{
    return NodeCount;
}


bool Graph::reachedClusterCount(int k)
{
    unordered_set<int> temp_set;
    int count = 0;
    for (auto &ii : V)
    {
        if (temp_set.find(ii.parent) == temp_set.end())
        {
            temp_set.insert(ii.parent);
            count++;
        }
    }
    
    return count <= k;
}

void Graph::print()
{
    printf("Node1\t\tNode2\t\tEdge\n");
    for (auto &ii : G)
    {
        printf("%d\t\t%d\t\t%d\n", ii.node1, ii.node2, ii.edge);
    }
}

void Graph::printU()
{
    for (auto &ii : V)
    {
        printf("Vertex: %d\tParent: %d\n", ii.vertix, ii.parent);
    }
}
