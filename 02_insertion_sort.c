#include <stdio.h>

void insertion_sort(int arr[], int n)
{
	int i, j ,x;
	for (i = 1; i < n; i++)
	{
		j = i - 1; 
		x = arr[i];
		while (j > -1 && arr[j] > x)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = x;
	}
}

int main(void)
{
	int arr[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
	int n = 10;

	insertion_sort(arr, n);

	int i = 0;
	while (i < n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");

	return 0;
}