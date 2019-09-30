//정렬이 안된 수들 중 k번째로 작은 수를 반환하는 함수를 만드시오. 전체 데이터를 정렬하지  말고 하시오.

#include <stdio.h>
#define MAX_ELEMENT 100

typedef struct {
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType* h) {
	h->heap_size = 0;
}
void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;

}

void print_heap(HeapType* h) {
	for (int i = 1; i <= h->heap_size; i++)
		printf("<%d> ", h->heap[i].key);
	printf("\n");
}

int k_return(HeapType* h, int k) {
	HeapType new_heap;
	init(&new_heap);
	for (int i = 1; i <= k; i++) {
		insert_max_heap(&new_heap, h->heap[i]);
	}

	element item = delete_max_heap(&new_heap);
	while (k < h->heap_size) {
		k++;
		if (item.key > h->heap[k].key) {
			insert_max_heap(&new_heap, h->heap[k]);
			item = delete_max_heap(&new_heap);
		}
	}
	return item.key;
}
void main() {
	element e[9] = { {10},{40},{30},{5},{12},{6},{15},{9},{60} };
	HeapType heap1;
	int i;
	element a;
	init(&heap1);
	for (i = 0; i < 9; i++)
		insert_max_heap(&heap1, e[i]);
	print_heap(&heap1);
	printf("1번째로 작은 수는 = %d\n", k_return(&heap1, 1));
	printf("2번째로 작은 수는 = %d\n", k_return(&heap1, 2));
	printf("3번째로 작은 수는 = %d\n", k_return(&heap1, 3));
	printf("4번째로 작은 수는 = %d\n", k_return(&heap1, 4));
	printf("5번째로 작은 수는 = %d\n", k_return(&heap1, 5));
	printf("6번째로 작은 수는 = %d\n", k_return(&heap1, 6));
	printf("7번째로 작은 수는 = %d\n", k_return(&heap1, 7));
	printf("8번째로 작은 수는 = %d\n", k_return(&heap1, 8));
}
