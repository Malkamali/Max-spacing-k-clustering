# Max-spacing-k-clustering
K-clustering aims to partition a graph into k number of groups. To insure that the members of the clusters share similarities, and to insure that different clusters have different properties, the smallest distance between two clusters is maximized. This project implements a clustering algorithm using C++. The code takes as input a graph, and then given k, the code will split the graph into k different group in such a way that maximizes the distance between any two groups.

The code was part of a school assignment.

# Input file

The program reads an input from a text file in the following format:
[number_of_nodes]

[edge 1 node 1] [edge 1 node 2] [edge 1 cost]

[edge 2 node 1] [edge 2 node 2] [edge 2 cost]


Refer to test.txt for an example input file.
