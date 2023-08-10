#include <stdio.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


void bubble_sort(int arr[], int n)
{
	int flag;
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		flag = 0;
		for (j = 0; j < n-1-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

int main(void)
{
	int arr[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
	int n = 10;

	bubble_sort(arr, n);

	int i = 0;
	while (i < n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");

	return 0;
}