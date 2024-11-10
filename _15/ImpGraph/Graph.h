//
// Created by ner13 on 10/11/2024.
//

#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include <unordered_map>
#include <vector>


//UNDIRECTED GRAPH

class Graph {

private:
    std::unordered_map<int, std::vector<int>> adjList;

public:

    Graph() = default;
    ~Graph() = default;

    void addVertex(int vertex);
    void addEdge(int src, int dst);
    void removeVertex(int vertex);
    void printGraph() const;
};



#endif //GRAPH_H
