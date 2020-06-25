#include <iostream>
// a structure to represent a weighted edge in graph
struct Edge{
    int src, dest, weight;
};
// a structure to represent a connected, directed and weighted graph
struct Graph{
    // V -> number of vertices, E-> Number of edges
    int V,E;
    // graph is represented as an array of edges
    struct Edge* edges;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E){
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edges = new Edge[E];
    return graph;
};
// A utility function used to print the solution 
void printArr(int dist[], int n){
    printf("Vertex distance from source\n");
    for(int i=0;i<n;++i)
        printf("%d\t\t%d\n",i,dist[i]);
}
// The main function that finds shortest distances from source to
// all other vertices using Bellman-Ford algorithm. The function
// also detects negative weight cycle
void BellmanFord(struct Graph* graph, int src){
    int V = graph->V;
    int E = graph->E;
    int* dist = new int[V];

    // Step 1: Initial distance from src to all other vetices as INFINITE
    for(int i=0;i<V;++i){
        dist[i]= INT_MAX;
    }
    dist[src]=0;
    // Step 2: Relax all edges |V|-1 times. A simple shortest
    // path from src to any other vertex can have at most |V|-1 edges
    for(int i =1; i<=V-1;++i){
        for(int j=0;j<E;++j){
            int u = graph->edges[j].src;
            int v = graph->edges[j].dest;
            int weight = graph->edges[j].weight;
            if(dist[u]!=INT_MAX && dist[u]+weight<=dist[v])
                dist[v]=dist[u]+weight;
        }
    }
    //step 3: check for negative=weight cycles. The above step guarantees 
    // shortest distances if graph doesn't contain
    // negative weight cycle. If we get a shorter path, then there 
    // is a cycle 
    for(int i=0;i<E;++i){
        int u = graph->edges[i].src;
        int v = graph->edges[i].dest;
        int weight = graph->edges[i].weight;
        if(dist[u]!=INT_MAX&& dist[u]+weight<dist[v]){ 
            printf("Graph contains negative weight cycle");
            return;
        }
    }
    printArr(dist,V);
}
// Driver program to test above functions 
int main() 
{ 
    /* Let us create the graph given in above example */
    int V = 5; // Number of vertices in graph 
    int E = 8; // Number of edges in graph 
    struct Graph* graph = createGraph(V, E); 
  
    // add edge 0-1 (or A-B in above figure) 
    graph->edges[0].src = 0; 
    graph->edges[0].dest = 1; 
    graph->edges[0].weight = -1; 
  
    // add edge 0-2 (or A-C in above figure) 
    graph->edges[1].src = 0; 
    graph->edges[1].dest = 2; 
    graph->edges[1].weight = 4; 
  
    // add edge 1-2 (or B-C in above figure) 
    graph->edges[2].src = 1; 
    graph->edges[2].dest = 2; 
    graph->edges[2].weight = 3; 
  
    // add edge 1-3 (or B-D in above figure) 
    graph->edges[3].src = 1; 
    graph->edges[3].dest = 3; 
    graph->edges[3].weight = 2; 
  
    // add edge 1-4 (or A-E in above figure) 
    graph->edges[4].src = 1; 
    graph->edges[4].dest = 4; 
    graph->edges[4].weight = 2; 
  
    // add edge 3-2 (or D-C in above figure) 
    graph->edges[5].src = 3; 
    graph->edges[5].dest = 2; 
    graph->edges[5].weight = 5; 
  
    // add edge 3-1 (or D-B in above figure) 
    graph->edges[6].src = 3; 
    graph->edges[6].dest = 1; 
    graph->edges[6].weight = 1; 
  
    // add edge 4-3 (or E-D in above figure) 
    graph->edges[7].src = 4; 
    graph->edges[7].dest = 3; 
    graph->edges[7].weight = -3; 
  
    BellmanFord(graph, 0); 
  
    return 0; 
} 