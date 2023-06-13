#include<stdio.h>
#include<stdlib.h>

struct Edge{
    int source,destination,weight;
};

struct Graph{
    int V,E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));
    
    return graph;
}

void bellmanFord(struct Graph* graph, int source){
    int V = graph->V;
    int E = graph->E;
    int sourceDest[V];
    
    for(int i=0;i<V;i++)
     sourceDest[i]= 999;
    
    sourceDest[source] = 0;
    
    for(int i=1;i<=V-1;i++){
        for(int j=0;j<E;j++){
            
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int w = graph->edge[j].weight;
            
            if(sourceDest[u]+w < sourceDest[v])
             sourceDest[v] = sourceDest[u]+w;
        }
    }
    
    for(int j=0;j<E;j++){
            
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int w = graph->edge[j].weight;
            if(sourceDest[u]+w < sourceDest[v])
             printf("negative cycle exists\n");
        }
    
    for(int i=0;i<V;i++){
        printf("\t %d \t %d\n",sourceDest[i],i);
    }    
}

int main(){
    int V,E,S;
    
    printf("enter the no of vertices\n");
    scanf("%d",&V);
    
    printf("Enter the no of edges\n");
    scanf("%d",&E);
    
    printf("enter the source node\n");
    scanf("%d",&S);
    
    struct Graph* graph = createGraph(V,E);
    
    for(int i=0;i<E;i++){
        printf("enter the source, destination, weight\n");
        scanf("%d%d%d",&graph->edge[i].source,&graph->edge[i].destination,&graph->edge[i].weight);
    }
    
    bellmanFord(graph,S);
}