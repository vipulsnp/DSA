#include <bits/stdc++.h>
using namespace std;

// ======================== Class Edge ===================================
class Edge
{
public:
    int src, dest;
};


// ======================== Class Graph ===================================

class Graph
{
public:
    int V, E;

    Edge* edge;
};

//===================== Find Subset Function to find the subset of Vertex i ====================
int findSubset(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return findSubset(parent, parent[i]);
}

// ========================= Check if graph contains cycle or not =========================

bool containsCycle(Graph* graph)
{
    int* parent = new int[graph->V];

    for(int i=0;i<graph->V;i++)
        parent[i]=-1;

    // Iterating through all the Edges and finding the subsets of vertices of each Edge
    for (int i = 0; i < graph->E; i++) {
        int x=findSubset(parent,graph->edge[i].src);
        int y=findSubset(parent,graph->edge[i].dest);
        if(x==y)    // If both subsets are same Then graphs contains cycle
            return true;
        parent[x]=y;
    }
    return false;
}

// ======================== Function to build graph with given Vertices and Edges ===================================

Graph* buildGraph(int V, int E)
{
    Graph* newGraph = new Graph();
    newGraph->V = V;
    newGraph->E = E;
    newGraph->edge = new Edge[newGraph->E];
    int i=0;
    while(i<E) {
        int src,dest;
        cout<<"------------------- Entry "<<i+1<<" -------------------\n";
        cout<<"Enter Source Vertex :"<<flush;
        cin>>src;
        cout<<"Enter Destination Vertex :"<<flush;
        cin>>dest;
        newGraph->edge[i].src = src;
        newGraph->edge[i].dest = dest;
        i++;
    }

    return newGraph;
}


// ================================ Main Function =================================

int main()
{
    int vertices,edges;
    cout<<"============================= Execution Started =============================\n"<<flush;
    cout<<"Enter vertices :"<<flush;
    cin>>vertices;
    cout<<"Enter Edges :"<<flush;
    cin>>edges;

    Graph* graph = buildGraph(vertices, edges);
    cout<<"-------------------------------------------------------------------------\n";
    if(containsCycle(graph))
        cout<<"Graph Contains Cycle !\n";
    else
        cout<<"Graph Doesn't contain Cycle!\n";

    return 0;
}
