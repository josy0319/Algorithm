#include <stdio.h>


void print_sort(int list[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%3d", list[i]);
	}
	printf("\n");
}

void inc_insertion_sort(int list[], int first, int last, int gap) {
	int i, j, key;
	for (i = first + gap; i <= last; i += gap) {
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap) {
			list[j + gap] = list[j];
		}
		list[j + gap] = key;
	}
}

void shell_sort(int list[], int n) {
	//갭 간격으로 서브 파일을 생성
	//삽입정렬함수를 호출
	int count = 0;
	for (int gap = n / 2; gap > 0; gap /= 2) {
		count++;
		if (gap % 2 == 0) gap++;
		for (int i = 0; i < gap; i++) {
			inc_insertion_sort(list, i, n - 1, gap);
		}
		printf("%d단계 : ", count);
		print_sort(list, n);
	}
}

int main() {
	int list[11] = { 10,8,6,20,4,3,22,1,0,15,16 };

	shell_sort(list, 11);
}