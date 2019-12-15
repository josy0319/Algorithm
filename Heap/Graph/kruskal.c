#include <stdio.h>
#include <stdlib.h>

typedef struct {

	int u; //간선의 끝점
	int v;  //간선의 끝점 
	int key; //간선의 가중치
}element;


void set_init(int n, int *parent)
{
	int i;
	for (i = 0; i<n; i++) {
		parent[i] = -1;
		
	}
}

int set_find(int curr, int *parent)
{
	if (parent[curr] == -1)
		return curr; 			// 루트 
	while (parent[curr] != -1) curr = parent[curr];
	return curr;
}

void set_union(int a, int b, int *parent)
{
	int root1 = set_find(a, parent);	// 노드 a의 루트를 찾는다. 
	int root2 = set_find(b, parent);	// 노드 b의 루트를 찾는다. 
	if (root1 != root2) 	// 합한다. 
		parent[root1] = root2;
}
int compare(const void *arg1, const void *arg2)
{
	element *p1 = (element *)arg1;
	element *p2 = (element *)arg2;
	return(p1->key - p2->key);
}

void kruskal(element A[], int n, int m)
{
	int edge_accepted = 0;//최소신장트리 간선수
	int k;
	int i = 0;
	int uset, vset;
	element e;
	//int *parent=new int[n];
	int *parent = (int*)malloc(sizeof(int)*n);  //각 정점의 부모
	
	set_init(n, parent); //각 정점은 자신을 자신의 부모로 초기화
	qsort(A, m, sizeof(element), compare); //간선의 키를 기준으로 간선을정렬
	while (edge_accepted<n - 1) 
	{
		e = A[i];
		uset = set_find(e.u, parent); //간선의 끝점에 대한 부모 찾음
		vset = set_find(e.v, parent); //
		if (uset != vset) { //양 끝점의 부모가 같지 않으면 즉  두 점사이 경로가 없으면
			printf("(%d ,%d) %d\n", e.u, e.v, e.key);
			edge_accepted++;
			set_union(uset, vset, parent); //간선을 최소신장트리에 추가 
			//간선 추가시마다 parent배열찍기 
		
			for (k = 0; k < n; k++)
				printf("%d ", parent[k]);
			printf("\n");
		}
		i++;
	}
	//delete []parent;
	



	free(parent);

}

void main()
{
	
	element A[9] = { { 0,1,29 },{ 1,2,16 },{ 2,3,12 },{ 3,4,22 },{ 4,5,27 },
	{ 0,5,10 },{ 1,6,15 },
	{ 3,6,18 },{ 4,6,25 } };
	int n = 7;//number of verteices
	int m = 9;//number of edges
	kruskal(A, n, m);
	
	/*
	element A[7] = { {0,1,1},{1,3,1}, {2,4,1}, {0,3,2},{3,4,2},{1,2,3}, {1,4,3} };

	int n = 5;//number of verteices
	int m = 7;//number of edges
	kruskal(A, n, m);
	*/


}