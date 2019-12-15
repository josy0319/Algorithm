#include <stdio.h>
#define MAX 8

int sorted[MAX];

void print_list(int list[]) {
	for (int i = 0; i < MAX; i++) {
		printf("%d ",list[i]);
	}
}

void merge(int list[], int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) 
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i > mid)
		for (int l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (int l = i; l <= mid; l++)
			sorted[k++] = list[l];

	//부분 정렬된 데이터를 배열list로 복사 sorted -> list로 복사
	for (int l = left; l <= right; l++) {
		list[l] = sorted[l];
		//printf("%d ",sorted[l]);
	}
	print_list(list);
	printf("\n");
}

void merge_sort(int list[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}

int main() {
	int list[MAX] = { 27,10,12,20,25,13,15,22 };
	merge_sort(list, 0, MAX-1);
	print_list(list);
}