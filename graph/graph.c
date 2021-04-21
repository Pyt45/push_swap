#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXV 100

typedef struct edgenode {
	int 		y; /* adjacency info */
	int 		weight; /* edge weight, if any */
	struct 		edgenode *next; /* next edge in list */
}				edgenode;

typedef struct {
	edgenode 	*edges[MAXV+1]; /* adjacency info */
	int 		degree[MAXV+1]; /* outdegree of each vertex */
	int 		nvertices; /* number of vertices in the graph */
	int 		nedges; /* number of edges in the graph */
	int 		directed; /* is the graph directed? */
} 				graph;

void initialize_graph(graph *g, int directed) {
	int 	i; /* counter */
	g->nvertices = 0;
	g->nedges = 0;
	g->directed = directed;

	for (i = 1; i <= MAXV; i++)
		g->degree[i] = 0;
	for (i = 1; i <= MAXV; i++)
		g->edges[i] = NULL;
}

void insert_edge(graph *g, int x, int y, int directed) {
	edgenode *p; /* temporary pointer */
	p = malloc(sizeof(edgenode)); /* allocate edgenode storage */
	p->weight = 0;
	p->y = y;
	p->next = g->edges[x];
	g->edges[x] = p; /* insert at head of list */
	g->degree[x]++;
	if (!directed)
		insert_edge(g, y, x, 1);
	else
		g->nedges++;
}

void read_graph(graph *g, int directed) {
	int i; /* counter */
	int m; /* number of edges */
	int x, y; /* vertices in edge (x,y) */
	initialize_graph(g, directed);
	scanf("%d %d", &(g->nvertices), &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &x, &y);
		insert_edge(g, x, y, directed);
	}
}

void print_graph(graph *g) {
	int i; /* counter */
	edgenode *p; /* temporary pointer */
	for (i = 1; i <= g->nvertices; i++)
	{
		printf("%d: ", i);
		p = g->edges[i];
		while (p != NULL)
		{
			printf(" %d", p->y);
			p = p->next;
		}
		printf("\n");
	}
}


int		main()
{
	graph	g;
	read_graph(&g, 1);
	print_graph(&g);
}