#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int left, int right) {
	int pivot = arr[left];
	int low = left+1;
	int high = right;

	while (low <= high) {
		while (low <= right && arr[low] <= pivot)
			low++;
		while (high >= (left+1) && arr[high] >= pivot)
			high--;
		if (low <= high)
			swap(&arr[low], &arr[high]);
	}
	swap(&arr[left], &arr[high]);

	return high;
}

int quick_select(int arr[], int left, int right, int select) {
	if (select > 0 && select <= right - left+1) {
		int pivot = partition(arr, left, right);

		if (pivot - left == select-1)
			return arr[pivot];
		else if (pivot - left > select-1)
			return quick_select(arr, left, pivot-1, select);
		else
			return quick_select(arr, pivot+1, right, select - pivot + left-1);
	}

	return -1;
}

int main(void) {
	int n, i, index;
	int *arr = NULL;

	scanf("%d", &n);  // 배열에 저장할 원소의 개수 입력
	scanf("%d", &index);  // 배열에서 탐색하고자 하는 원소의 인덱스 입력

	arr = (int *)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)  // n개의 양의 정수 입력
		scanf("%d", &arr[i]);
	quick_select(arr, 0, n-1, index);

	printf("\n정렬된 배열:");
	for(i = 0; i < n; i++)
		printf("%3d", arr[i]);
	printf("\n");

	printf("%d 번째 원소: %d\n", index, quick_select(arr, 0, n-1, index));

	free(arr);

	return 0;
}
