#ifndef graph_hpp
#define graph_hpp

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

class Graph
{
private:
    struct E_Struct // A structure that stores two vertiecies and the edge value between them
    {
        int node1;
        int node2;
        int edge;
    };
    int NodeCount;
    
    struct cluster  // Remembers the parent of each vertix.
    {
        int vertix;
        int parent;
    };
    
public:
    vector<E_Struct> G; // A vector of edges (equivilent to an adjacency list)
    vector<cluster> V;  // A vector of clusters. Initially there are NodeCount clusters with each vertix being its own parent.
    // Graph initializer that reserves memory for a graph with 'numNodes' number of nodes.
    Graph(int numNodes): NodeCount(numNodes) {G.reserve(NodeCount); V.reserve(numNodes); }
    
    int nodeCount();    // Returns the number of nodes
    void addEdge(int v1, int v2, int ec);   // Adds an edge to the vector G. inputs are vertix1, verix2, and edge cost
    void sort();    // Sorts the nodes in increasing edge costs
    void makeClusters();    // Creates the initial clusters (NumNodes clusters where each node is its own cluster and parent)
    int find(int vertex);   // Returns the parent of the vertex
    void Union(int vertex1, int vertex2);   // Merges two clusters, assigning the parent of the first cluster as the new parent
                                            // of the merged cluster
    
    void print();   // Prints the graph
    bool compare(E_Struct a, E_Struct b);   // Compares two nodes and returns true if the edge cost of 'a' is smaller than
                                            // the edge cost of 'b'. If both have the same edge cost, returns true if the index
                                            // if the left vertix of 'a' is smaller than 'b'. Used in sort().
    
    void printU();  // Prints the current clustering (Prints each vertex's parent)
    bool reachedClusterCount(int k);    // Returns true if the number of clusters is <= k. A faster implimentation in main.cpp is
                                        // used instead of this function

};
#endif /* graph_hpp */
