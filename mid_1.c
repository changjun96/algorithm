#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int list[], int n) {
	int i, j;
	int minLoc;

	for (i = 0; i < n-1; i++) {
		minLoc = i;

		for (j = i+1; j < n; j++) {
			if (list[j] < list[minLoc])
				minLoc = j;
		}

		swap(&list[i], &list[minLoc]);

		for (j = 0; j < n; j++)
			printf("%3d", list[j]);
		printf("\n");
	}
}

int main(void) {
	int n, i;
	int *arr = NULL;

	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("\n");
	selection_sort(arr, n);

	printf("\n정렬된 배열:");
	for (i = 0; i < n; i++)
		printf("%3d", arr[i]);
	printf("\n");

	free(arr);

	return 0;
}
