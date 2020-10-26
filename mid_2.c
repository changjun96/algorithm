#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 256

int sorted[MAX_SIZE];

// 합병 정렬 함수
void merge(int list[], int left, int mid, int right, int size) {
	int i, j, k, l;

	i = left;
	j = mid+1;
	k = left;

	// 분할 정렬된 list의 병합
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	// list 배열의 왼쪽에 값들이 남아있을 경우
	while (i <= mid)
		sorted[k++] = list[i++];  // list 배열 왼쪽에 남은 값들을 sorted 배열에 추가

	// list 배열의 오른쪽에 값들이 남아있을 경우
	while (j <= right)
		sorted[k++] = list[j++];  // list 배열 오른쪽에 남은 값들을 sorted 배열에 추가

	for (l = left; l <= right; l++)
		list[l] = sorted[l];      // sorted 배열에 존재하는 값을 list 배열에 복사

	for (l = 0; l < left; l++)
		printf("  -");

	for (l = left; l <= right; l++)
		printf("%3d", list[l]);

	for (l = right+1; l < size; l++)
		printf("  -");
	printf("\n");
}

void merge_sort(int list[], int left, int right, int size) {
	int mid;

	if(left < right) {
		mid = (left + right) / 2;  // list 배열의 균등 분할
		merge_sort(list, left, mid, size);  // 재귀 호출을 통해 list 배열의 왼쪽 부분 정렬
		merge_sort(list, mid+1, right, size);  // 재귀 호출을 통해 list 배열의 오른쪽 부분 정렬
		merge(list, left, mid, right, size);  // 병합
	}
}

int main(void) {
	int n, i;
	int arr[MAX_SIZE];

	scanf("%d", &n);  // 배열에 저장할 원소의 개수 입력

	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);  // 배열에 저장할 원소 입력
	printf("\n");
	merge_sort(arr, 0, n-1, n);  // 배열의 전체 범위를 지정

	printf("\n정렬된 배열:");
	for(i = 0; i < n; i++)
		printf("%3d", arr[i]);
	printf("\n");

	return 0;
}
