#include <stdio.h>
#include <limits.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int l, int h)
{
	int pivot = arr[l];
	int i = 0;
	int j = h;

	do
	{
		do {i++;} while (arr[i] <= pivot);
		do {j--;} while (arr[j] > pivot);
		if (i < j)
		{
			swap(&arr[i], &arr[j]);
		}
	}
	while (i < j);
	swap(&arr[l], &arr[j]);
	return j;
}

void quick_sort(int arr[], int l, int h)
{
	int j;
	if (l < h)
	{
		j = partition(arr, l, h);
		quick_sort(arr, l, j);
		quick_sort(arr, j+1, h);
	}
}

int main(void)
{
	int arr[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, INT_MAX};
	int n = 11;

	quick_sort(arr, 0, n-1);

	int i = 0;
	while (i < n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");

	return 0;
}