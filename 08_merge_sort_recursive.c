#include <stdio.h>

void merge(int arr[], int l, int mid, int h)
{
	int i = l, j = mid + 1, k = l;
	int sol[100];

	while (i <= mid && j <= h)
	{
		if (arr[i] < arr[j])
		{
			sol[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			sol[k] = arr[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		sol[k] = arr[i];
		k++;
		i++;
	} 
	while (j <= h)
	{
		sol[k] = arr[j];
		k++;
		j++;
	}
	i = l;
	while (i <= h)
	{
		arr[i] = sol[i];
		i++;
	}
}

void r_merge_sort(int arr[], int l, int h)
{
	int mid;
	if (l < h)
	{
		mid = (l + h) / 2;
		r_merge_sort(arr, l, mid);
		r_merge_sort(arr, mid + 1, h);
		merge(arr, l, mid, h);
	}
}

int main(void)
{
	int arr[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
	int n = 10;
	int l = 0;
	int h = n-1;

	r_merge_sort(arr, l, h);

	int i = 0;
	while (i < n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");

	return 0;
}