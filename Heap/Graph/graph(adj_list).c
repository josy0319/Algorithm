#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

void graph_init(GraphType* g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		printf("그래프:정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v)
{
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		printf("그래프: 정점 번호 오류");
		return;
	}

	//node=new GraphNode;
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

void print_graph(GraphType* g)
{
	int i;
	GraphNode* node;
	printf("List of edges:\n");
	for (i = 0; i < g->n; i++) {
		node = g->adj_list[i];
		while (node != NULL) {
			printf("<%d, %d>", i, node->vertex);
			node = node->link;
		}
		printf("\n");
	}
	printf("\n");
}

GraphNode* findNode(GraphNode* node, int vertex)
{
	while (node != NULL) {
		if (node->vertex == vertex)
			return node;
		node = node->link;
	}
	return node;
}

void delete_edge(GraphType* g, int u, int v)
{
	if (u >= g->n || v >= g->n) {
		printf("그래프: 정점 번호 오류");
		return;
	}
	GraphNode* node;
	node = findNode(g->adj_list[u], v);
	if (node != NULL) {
		if (g->adj_list[u] != node) {
			GraphNode* temp = g->adj_list[u];
			while (temp->link != node)
				temp = temp->link;
			temp->link = node->link;
		}
		else {
			g->adj_list[u] = node->link;
		}
		//delete node;
		free(node);
	}
}
int out_degree(GraphType* g, int v) {
	GraphNode* node;
	int degree = 0;
	for (node = g->adj_list[v]; node; node = node->link)
		if (node != 0) degree++;
	return degree;
}
int in_degree(GraphType* g, int v) {
	int degree = 0;
	GraphNode* node;
	for (int i = 0; i < g->n; i++)
		for (node = g->adj_list[i]; node; node = node->link)
			if (node->vertex == v) degree++;
	return degree;
}


void main()
{
	int i;
	GraphType g;
	graph_init(&g);

	for (i = 0; i < 4; i++)
		insert_vertex(&g, i);
	insert_edge(&g, 0, 1);
	insert_edge(&g, 1, 0);
	insert_edge(&g, 0, 3);
	insert_edge(&g, 3, 0);
	insert_edge(&g, 1, 2);
	insert_edge(&g, 2, 1);
	insert_edge(&g, 1, 3);
	insert_edge(&g, 3, 1);
	insert_edge(&g, 2, 3);
	insert_edge(&g, 3, 2);
	print_graph(&g);
	printf("진출 차수 = %d\n", out_degree(&g, 0));
	printf("진출 차수 = %d\n", out_degree(&g, 1));
	printf("진출 차수 = %d\n", out_degree(&g, 2));
	printf("진출 차수 = %d\n", out_degree(&g, 3));
	printf("\n");
	printf("진입 차수 = %d\n", in_degree(&g, 0));
	printf("진입 차수 = %d\n", in_degree(&g, 1));
	printf("진입 차수 = %d\n", in_degree(&g, 2));
	printf("진입 차수 = %d\n", in_degree(&g, 3));

	delete_edge(&g, 0, 1);
	delete_edge(&g, 1, 0);
	print_graph(&g);
	printf("진출 차수 = %d\n", out_degree(&g, 0));
	printf("진출 차수 = %d\n", out_degree(&g, 1));
	printf("진출 차수 = %d\n", out_degree(&g, 2));
	printf("진출 차수 = %d\n", out_degree(&g, 3));
	printf("\n");
	printf("진입 차수 = %d\n", in_degree(&g, 0));
	printf("진입 차수 = %d\n", in_degree(&g, 1));
	printf("진입 차수 = %d\n", in_degree(&g, 2));
	printf("진입 차수 = %d\n", in_degree(&g, 3));
	delete_edge(&g, 1, 2);
	print_graph(&g);
}

