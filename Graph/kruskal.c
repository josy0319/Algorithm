#include <stdio.h>
#include <stdlib.h>

typedef struct {

	int u; //������ ����
	int v;  //������ ���� 
	int key; //������ ����ġ
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
		return curr; 			// ��Ʈ 
	while (parent[curr] != -1) curr = parent[curr];
	return curr;
}

void set_union(int a, int b, int *parent)
{
	int root1 = set_find(a, parent);	// ��� a�� ��Ʈ�� ã�´�. 
	int root2 = set_find(b, parent);	// ��� b�� ��Ʈ�� ã�´�. 
	if (root1 != root2) 	// ���Ѵ�. 
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
	int edge_accepted = 0;//�ּҽ���Ʈ�� ������
	int k;
	int i = 0;
	int uset, vset;
	element e;
	//int *parent=new int[n];
	int *parent = (int*)malloc(sizeof(int)*n);  //�� ������ �θ�
	
	set_init(n, parent); //�� ������ �ڽ��� �ڽ��� �θ�� �ʱ�ȭ
	qsort(A, m, sizeof(element), compare); //������ Ű�� �������� ����������
	while (edge_accepted<n - 1) 
	{
		e = A[i];
		uset = set_find(e.u, parent); //������ ������ ���� �θ� ã��
		vset = set_find(e.v, parent); //
		if (uset != vset) { //�� ������ �θ� ���� ������ ��  �� ������ ��ΰ� ������
			printf("(%d ,%d) %d\n", e.u, e.v, e.key);
			edge_accepted++;
			set_union(uset, vset, parent); //������ �ּҽ���Ʈ���� �߰� 
			//���� �߰��ø��� parent�迭��� 
		
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