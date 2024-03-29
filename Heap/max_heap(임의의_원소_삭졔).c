// max heap에서 임의의 원소를 삭제하는 함수를 다음과 같이 작성하시오
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

void delete_element(HeapType* h, int number) {
	int parent;
	for (int i = 1; i <= h->heap_size; i++) {
		if (h->heap[i].key == number) {
			parent = i;
		}
	}
	element temp;
	temp = h->heap[(h->heap_size)--];
	int child = parent * 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))
			child++;
		if (temp.key >= h->heap[child].key) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
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
	int num = 40;
	delete_element(&heap1, num);
	print_heap(&heap1);
	//max heap인지 체크하는 과정   값이 큰 순서대로 출력되어야 한다
	for (i = 0; i < 8; i++) {
		a = delete_max_heap(&heap1);
		printf("%d ", a.key);
	}
}
