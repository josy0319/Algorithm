#include <stdio.h>
int search_binary(int list[], int key, int low, int high) {
	int middle;
	int i = 1;
	while (low <= high) {
		printf("%d번 실행\n", i++);
		middle = (low + high)/2;
		if (key == list[middle]) return middle;	//인덱스값을 반환
		else if (key < list[middle]) high = middle - 1;
		else low = middle + 1;
	}
	return -1;
}

int search_binary_rec(int list[], int key, int low, int high) {
	int middle;
	static int cnt = 1;
	printf("%d번 실행\n", cnt++);
	if (low <= high) {
		middle = (low + high) / 2;
		if (key == list[middle]) return middle;
		else if (key < list[middle])
			return search_binary_rec(list, key, low, middle - 1);
		else return search_binary_rec(list, key, middle + 1, high);
	}
	return -1;

}
int main() {
	int list[] = { 2,6,11,13,18,20,22,27,29,
		30,34,38,41,42,45,47 };
	int k;
	scanf_s("%d", &k);
	int res = search_binary_rec(list, k, 0, 15);
	if (res >= 0) printf("검색값 %d를 찾음\n", k);
	else printf("검색값 %d가 없음\n", k);
}
