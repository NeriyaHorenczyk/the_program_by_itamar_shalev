#include <iostream>

#include "Graph.h"
using namespace std;

int main()
{

    Graph graph;

    cout << "Enter the number of nodes: ";
    int n;
    cin >> n;
    cout << "Enter the vertices followed by spaces: \n";
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        graph.addVertex(val);
    }

    cout << "Enter the edges you want in the graph in the next format:\n";
    cout << "(source,target)\n";
    int src, dest;
    char c;
    do
    {
        cin >> c >> src >> c >> dest >> c;
        graph.addEdge(src,dest);
        cout << "Add another edge?(y/n) ";
        cin >> c;

    } while (c == 'y');

    graph.printGraph();

    return 0;
}
