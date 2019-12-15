#include <stdio.h>
#define MAX_VERTICES 50
#define TRUE 1
#define FALSE 0

int visited[MAX_VERTICES];

typedef struct{
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

void graph_init(GraphType *g)
{
	int r,c;
	g->n=0;
	for(r=0;r<MAX_VERTICES;r++)
		for(c=0;c<MAX_VERTICES;c++)
			g->adj_mat[r][c]=0;
}

void insert_vertex(GraphType *g,int v)
{
	if(((g->n)+1)> MAX_VERTICES){
		printf("그래프:정점의 개수 초과");
		return;
	}
	g->n++;
}

void delete_vertex(GraphType *g, int v)
{
	if(v>=g->n || v<0){
		printf("error\n");
		return;
	}
	g->n--;
}
//insert edge in undirected graph(무방향 그래프)
void insert_edge(GraphType *g, int start, int end)
{
	if(start>=g->n || end>=g->n){
		printf("그래프 :정점 번호 오류");
	}

	g->adj_mat[start][end]=1;
	g->adj_mat[end][start]=1;
}

void delete_edge(GraphType *g, int start, int end)
{
	if(start>=g->n || end>=g->n){
		printf("그래프 :정점 번호 오류");
	}

	g->adj_mat[start][end]=0;
	g->adj_mat[end][start]=0;
}


void print_graph(GraphType *g)
{
	int r,c;
	for(r=0;r<g->n;r++)
		for(c=0;c<g->n;c++){
			if(g->adj_mat[r][c])
				printf("<%d , %d>",r,c);
		}

		printf("\n");
}

void dfs_mat(GraphType *g, int v)
{
	int w;
	visited[v]=TRUE;
	printf("%d ", v);
	for(w=0;w<g->n;w++)
		if(g->adj_mat[v][w] && !visited[w])
			dfs_mat(g,w);
}

void main()
{
	int i;
	GraphType g;
	graph_init(&g);

	for(i=0;i<4;i++)
		insert_vertex(&g,i);
	insert_edge(&g,0,1);
//	insert_edge(&g,1,0);
	insert_edge(&g,0,3);
	insert_edge(&g,1,2);
	insert_edge(&g,1,3);
	insert_edge(&g,2,3);
	print_graph(&g);

	//dfs_mat(&g,0);
	printf("\n");
	delete_edge(&g,0,1);
    dfs_mat(&g,0);
	printf("\n");

	print_graph(&g);

}
