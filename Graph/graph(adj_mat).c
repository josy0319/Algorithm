#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphType {
	int n;	// 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// 그래프 초기화 
void init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}
// 정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}
// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void delete_edge(GraphType* g, int start, int end)
{
	if (g->n <= start || g->n <= end) return;
	g->adj_mat[start][end] = 0;
	g->adj_mat[end][start] = 0;
}

// 인접 행렬 출력 함수
void print_adj_mat(GraphType* g)
{
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			printf("%2d ", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}
int out_degree(GraphType* g, int v) {
	int degree = 0;
	for (int i = 0; i < g->n; i++)
		if (g->adj_mat[v][i] != 0) degree++;
	return degree;
}
int in_degree(GraphType* g, int v) {
	int degree = 0;
	for (int i = 0; i < g->n; i++)
		if (g->adj_mat[i][v] != 0) degree++;
	return degree;
}
int edge_num(GraphType* g) {
	int score = 0;
	for (int i = 0; i < g->n; i++)
		for (int j = 0; j < g->n; j++)
			if (g->adj_mat[i][j] != 0) score++;
	return score / 2;
}

void main()
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 4; i++)

		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_mat(g);
	printf("\n");
	delete_edge(g, 2, 3);
	print_adj_mat(g);

	printf("진출 차수 = %d \n", out_degree(g, 1));
	printf("진입 차수 = %d \n", in_degree(g, 2));
	printf("엣지 갯수 = %d \n", edge_num(g));

	free(g);
}