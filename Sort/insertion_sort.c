#include <stdio.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(x))

void print_sort(int list[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%3d", list[i]);
	}
	printf("\n");
}

void insertion_sort(int list[], int n) {
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
		printf("%d단계 : ", i);
		print_sort(list, i);
	}
}



int main() {
	int list[6] = { 5,3,8,1,2,7 };
	insertion_sort(list, 6);
}