
// ================================ Algorithm II ================================

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


// ======================== Class Subset ===================================

class Subset {
public:
    int parent,rank;
};


//===================== Find Subset Function to find the subset of Vertex i ====================
int findSubset(Subset parent[], int i)
{
    if (parent[i].parent == i)
        return parent[i].parent;

        parent[i].parent = findSubset(parent, parent[i].parent);

}

//===================== Union Function ====================
void Union(Subset parent[], int i,int j)
{

    if (parent[i].rank < parent[j].rank)
        parent[i].parent = j;
    else if (parent[i].rank > parent[j].rank)
        parent[j].parent = i;
    else {          // This is if ranks are same
        parent[j].parent = i;
        parent[i].rank++;   // Increase the rank by 1
    }
}


// ========================= Check if graph contains cycle or not =========================

bool containsCycle(Graph* graph)
{
    // ============================ Create V subsets ============================
    Subset* parent = new Subset[graph->V];

    for(int i=0;i<graph->V;i++)
    {
        parent[i].parent = i;
        parent[i].rank = 0;
    }

    // Iterating through all the Edges and finding the subsets of vertices of each Edge
    for (int i = 0; i < graph->E; i++) {
        int s1=findSubset(parent,graph->edge[i].src);
        int s2=findSubset(parent,graph->edge[i].dest);
        if(s1==s2)    // If both subsets are same Then graphs contains cycle
            return true;

        // Call the Union function
        Union(parent,s1,s2);

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
