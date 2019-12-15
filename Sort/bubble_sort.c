#include <stdio.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(x))

void print_sort(int list[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%3d", list[i]);
	}
	printf("\n");
}

void bubble_sort(int list[], int n) {
	int temp;
	int count = 0;
	for (int i = n - 1; i >= 0; i--) {
		count++;
		for (int j = 0; j < n - 1; j++) {
			if (list[j] > list[j + 1]) {
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
		printf("%d단계 : ", count);
		print_sort(list, 6);
	}
}

void bubble_sort_with_mecro(int list[], int n) {
	int temp;
	int count = 0;
	for (int i = n - 1; i >= 0; i--) {
		count++;
		for (int j = 0; j < n - 1; j++) {
			if (list[j] > list[j + 1]) {
				SWAP(list[j], list[j + 1], temp);
			}
		}
		printf("%d단계 : ", count);
		print_sort(list, 6);
	}
}

int main() {
	int list[6] = { 5,3,8,1,2,7 };
	bubble_sort(list, 6);
}