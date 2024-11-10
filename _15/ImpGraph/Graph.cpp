//
// Created by ner13 on 10/11/2024.
//

#include "Graph.h"
using namespace std;

void Graph::addVertex(int vertex)
{
    if(adjList.find(vertex) == adjList.end())
        adjList[vertex] = {}; //init an empty edges list
    else
        cout << "Vertex " << vertex << " already exists." << endl;
}

void Graph::addEdge(int src, int dst)
{
    if(adjList.find(src) == adjList.end()) //if src doesn't exist
        addVertex(src); //add the src to the graph
    if(adjList.find(dst) == adjList.end()) //if std doesn't exist
        addVertex(dst); //add the dst to the graph

    //adds the edge to both of the nodes
    adjList[src].push_back(dst);
    adjList[dst].push_back(src);

}

void Graph::removeVertex(int vertex)
{
    if(adjList.find(vertex) == adjList.end())
        cout << "Vertex " << vertex << " does not exists." << endl;
    else
        adjList.erase(vertex);
}


void Graph::printGraph() const
{
    for(const auto& vertex : adjList)
    {
        cout << "Vertex " << vertex.first << ": ";
        for(auto neighbour : vertex.second)
            cout << neighbour << " ";
        cout << endl;
    }
}
