#include <stdio.h>
#include <stdlib.h>

//https://github.com/josy0319/Algorithm.git

#define MAX_ELEMENT 200
typedef struct {
	int key;
}element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType* h)
{
	h->heap_size = 0;
}

//left_child of i=i*k-(k-2)
//parent index of l=(l+k-2)/k

void insert_max_heap(HeapType* h, element item, int k){
	//k-max-heap(자식이 k개인 완전 k-nary tree를 이용한 heap))이 되도록 자료를          //입력
	int i = ++(h->heap_size);
	while ((i != 1) && (item.key > h->heap[(i + k - 2) / k].key)) {
		h->heap[i] = h->heap[(i + k - 2) / k];
		i = (i + k - 2) / k;
	}
	h->heap[i] = item;
}
int max_num(element heap[], int start, int number){
	//heap의 start에서 number 개 만큼의 원소 중 가장 key가 큰 원소의 index를 반          //환하다.
	int max = heap[start].key;
	int index=start;
	for (int i = start, k = 0; k < number; i++, k++){
		if (heap[i].key > max){
			max = heap[i].key;
			index = i;
		}
	}
	return index;
}
element delete_max_heap(HeapType* h, int k){
	//k-max-heap에서 가장 key가 큰 원소를 반환한다. 반환 후 k-max-heap을 유지               //한다. 위의 max_num함수를 이용
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	int parent = 1;
	int child = 2;
	while (child <= h->heap_size) {
		if (child < h->heap_size)
			child = max_num(h, parent * k - (k - 2), k);
		if (temp.key > h->heap[child].key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child = child * k - (k - 2);
	}
	h->heap[parent] = temp;
	return item;
}

void heap_sort(element a[], int n, int k)
{ //k-max-heap을 이용하여 정렬한다.
	int i;
	HeapType h;
	init(&h);
	for (i = 0; i < n; i++) {
		insert_max_heap(&h, a[i], k);
	}
	for (i = n - 1; i >= 0; i--) {
		a[i] = delete_max_heap(&h, k);
	}
	for (i = 1;i < n;i++)
		printf("%d ", a[i].key);

}

void print_heap(HeapType* h)
{
	for (int i = 1; i <= h->heap_size; i++)
		printf("<%d> ", h->heap[i].key);
	printf("\n");
}
void main()
{
	HeapType heap;
	element e[10] = { {10},{40},{30},{5},{12},{6},{15},{9},{60},{70} };
	init(&heap);
	for (int i = 0; i < 10; i++)
		insert_max_heap(&heap, e[i], 4);
	print_heap(&heap);
	heap_sort(&heap,10,4);
}
