#include <stdio.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int arr[], int n)
{
	int i, j, k;
	for (i = 0; i < n - 1; i++)
	{
		for (j = k = i; j < n; j++)
		{
			if (arr[j] < arr[k])
			{
				k = j;
			}
		}
		swap(&arr[i], &arr[k]);
	}
}

int main(void)
{
	int arr[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
	int n = 10;

	selection_sort(arr, n);

	int i = 0;
	while (i < n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");

	return 0;
}