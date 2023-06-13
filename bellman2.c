#include<stdio.h>

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