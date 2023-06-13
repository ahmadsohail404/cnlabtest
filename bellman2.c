#include<stdio.h>

struct Edge{
  int source, destination, weight;
};

struct Graph{
  int V,E;
  struct Edge* edge;
};

struct Graph* createGraph(int V, int E){
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->V = V;
  graph->E = E;
  graph->edge = (struct Edge*)malloc(graph->E sizeof(struct Edge));

  return graph;
}


int main(){
  int V,E,S;
  scanf("%d", &V);
  scanf("%d", &E);
  scanf("%d", &S);

  struct Graph* graph = createGraph(V,E);
  printf("Enter the source, destination, weight\n");
  for(int i=0;i<E;i++){
    scanf("%d%d%d", graph->edge[i].source, graph->edge[i].destination, graph->edge[i].weight);
  }
  bellmanFord(graph, S);
}