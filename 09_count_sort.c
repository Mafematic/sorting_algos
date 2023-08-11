#include <stdio.h>
#include <stdlib.h>

int find_max(int arr[], int n)
{
	int max = arr[0]; // max = INT32_MIN
	int i = 0;
	while (i < n)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		i++;
	}
	return max;
}

void count_sort(int arr[], int n)
{
	int max; 
	int *copy;

	max = find_max(arr, n);
	copy = (int*)malloc(sizeof(int) * (max + 1));

	int i = 0;
	while (i < max + 1)
	{
		copy[i] = 0;
		i++;
	}
	i = 0;
	while (i < n)
	{
		copy[arr[i]]++;
		i++;
	}
	int j = 0;
	i = 0;
	while (j < max + 1)
	{
		if (copy[j] > 0)
		{
			arr[i] = j;
			i++;
			copy[j]--;
		}
		else 
		{
			j++;
		}
	}
	free(copy);
}


int main(void)
{
	int arr[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
	int n = 10;

	count_sort(arr, n);

	int i = 0;
	while (i < n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");

	return 0;
}