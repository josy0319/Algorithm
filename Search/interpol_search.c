#include <stdio.h>
int interpol_search(int list[], int key, int n) {
	int low, high, j;
	int cnt = 1;
	low = 0;
	high = n - 1;
	while ((list[high] >= key) && key > list[low]) {
		printf("%d번 실행\n", cnt++);
		j = ((float)(key - list[low]) / (list[high] - list[low]) * (high - low)) * low;
		if (key > list[j]) low = j + 1;
		else if (key < list[j]) high = j - 1;
		else low = j;
	}
	if (list[low] == key) return low;
	else return -1;
}

int main() {
	int list[] = { 2,6,11,13,18,20,22,27,29,
		30,34,38,41,42,45,47 };
	int k;
	scanf_s("%d", &k);
	int res = interpol_search(list, k, 16);
	if (res >= 0) printf("검색값 %d를 찾음\n", k);
	else printf("검색값 %d가 없음\n", k);
}
