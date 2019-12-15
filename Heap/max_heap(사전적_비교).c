/*위 구조체를 사용하여  세 원소 이상 max heap에 입력하고 삭제 해 보시오. 결과를 화면에 매번 찍도록 하시오. 
두 원소의 크기를 문자열 key에 따르도록 하시오. 즉 사전적 크기 비교를 이용하시오.
예를 들면 e1={"egg", 1234},e2={"structure", 321}이면 e1가 e2보다 작다고 생각한다.
문자열의 사전적 크기를 비교하는 함수 strcmp를 이용한다.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 10
typedef struct {
	char key[20];
	int id;
}element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

void init(HeapType* h)
{
	h->heap_size = 0;
}
void insert_heap(HeapType* h, element item) {
	int i = ++(h->heap_size);
	while ((i != 1) && (strcmp(item.key, h->heap[i / 2].key)) > 0) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}
element delete_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (strcmp(h->heap[child].key, h->heap[child + 1].key)) < 0)
			child++;
		if (strcmp(temp.key, h->heap[child].key) >= 0) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
int main(void) {
	HeapType* heap = (HeapType*)malloc(sizeof(HeapType));
	init(heap);

	element item, item1, item2, item3;

	item.id = 4;
	item.key[19] = 'aaa';

	item1.id = 2;
	item1.key[19] = 'ccc';

	item2.id = 1;
	item2.key[19] = 'ddd';

	item3.id = 3;
	item3.key[19] = 'bbb';

	insert_heap(heap, item);
	insert_heap(heap, item1);
	insert_heap(heap, item2);
	insert_heap(heap, item3);

	element item4, item5, item6, item7;
	item4 = delete_heap(heap);
	printf("< %d > \n", item4.id);
	item5 = delete_heap(heap);
	printf("< %d > \n", item5.id);
	item6 = delete_heap(heap);
	printf("< %d > \n", item6.id);
	item7 = delete_heap(heap);
	printf("< %d > \n", item7.id);
}
