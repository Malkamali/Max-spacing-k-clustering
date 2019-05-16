// --------------------------- K-Clustering -----------------------------------
/*
 This program computes the max spacing k-clusters. Given a graph, k-clustering is grouping the nodes of the graph into k number
 of clusters. Max spacing k-clusters algorithm is an algortithm that k-clusters a graph in a way that maximizes the distances
 between each cluster.
 
 The program reads a graph from a text file formatted in a specific way and uses the class graph to store and process the data.
 The algorithm works by sorting the inputs from smalles edge cost to largest, merging the two neares clusters (subtracting
 one cluster from the total number of cluster), and repeating until the number of clusters is k.
 */


#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "graph.hpp"

using namespace std;

// Reads and stores a text file containing the graph data. Input is the path to the external text file.
Graph getGraph(string Str)
{
    
    // Read file using input string as file path
    ifstream file;
    file.open(Str);
    
    // Create string to dump lines from external file
    string strng;
    
    getline(file,strng);
    Graph myG(stoi(strng));
    
    if (!file.good())
    {
        cerr << "File Error";
    }
    
    /* While each line is being read, add edges to myG line by line */
    while (file.good()) {
        while (getline(file, strng)) {
            istringstream ss(strng);
            string node1; // Store source vertix. To be pushed to the map
            string node2; // Store destination verticies
            string edgeCost;
            getline(ss, node1, ' ');
            getline(ss, node2, ' ');
            getline(ss, edgeCost);
            myG.addEdge(stoi(node1), stoi(node2), stoi(edgeCost));
            }
        }
    
    file.close();
    myG.sort();
    //myG.print();  // Uncomment to double check if file has been correctly read.
    myG.makeClusters();
    return myG;
}

// Main algorithm for finding the max spacing of k-clusters. Inputs are the graph to be proccessed and k.
int maxSpacing(Graph &g, int k)
{
    int current_cluster_count = g.nodeCount();
    int maxSpace = -1;
    for (auto &ii : g.G)
    {
        if (g.find(ii.node1) != g.find(ii.node2))   // If the two vericies of this node are not in the same cluster
        {
            // Halt if the number of clusters = k and retun the node's edge cost as the max spacing
            if (current_cluster_count <= k)
            {
                maxSpace = ii.edge;
                g.printU(); // Prints which cluster each verix belongs to
                return maxSpace;
            }
            // Else merge the two vericies of this node
            maxSpace = ii.edge;
            //printf("Merging %d with %d\n", ii.node1, ii.node2);   // Uncomment to print code execution log
            g.Union(ii.node1, ii.node2);
            --current_cluster_count;
            }
        }
    return -1;  // Return a negative value if the code did not execute
}

int main(int argc, const char * argv[]) {
    Graph myG = getGraph("~/Documents/cluster/cluster/test.txt");
    cout << maxSpacing(myG, 4) << endl;
    return 0;
}
