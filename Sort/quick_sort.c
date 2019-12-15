#include <stdio.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(x))

void print_sort(int list[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%3d", list[i]);
	}
	printf("\n");
}

int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;
	low = left;
	high = right+1;
	pivot = list[left];
	do {
		do {
			low++;
		} while (list[low] < pivot); // 큰 값 찾으면 멈춤
		do {
			high--;
		} while (list[high] > pivot); // 작은 값 찾으면 멈춤

		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);
	SWAP(list[high], list[left], temp);
	return high;
}

void quick_sort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list,left,right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

int main() {
	int list[11] = { 5,3,8,4,9,1,6,2,7 };

	quick_sort(list, 0,9);
}