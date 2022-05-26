
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#define VISIED -1

static int countReached(Graph g, int reached, int src, int *visited, int total);

int numReachable(Graph g, int src) {
	int reached = 1;
	int total =  GraphNumVertices(g);
	
	int *visited = malloc(total * sizeof(int));
    for (int v = 0; v < total; v++) {
        visited[v] = 0;
    }
	visited[src] = VISIED;

	reached = countReached(g, reached, src, visited, total);
	free(visited);
	return reached;
}

static int countReached(Graph g, int reached, int src, 
int *visited, int total) {
	for (int v = 0; v < total; v++) {
		if (src != v && GraphIsAdjacent(g, v, src) == true 
		&& visited[v] != VISIED) {
			reached++;
			visited[v] = VISIED;
			reached = countReached(g, reached, v, visited, total);
		}
	}
	return reached;
}

