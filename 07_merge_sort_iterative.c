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


void i_merge_sort(int arr[], int n)
{
	int p, i, l, mid, h;

	for (p = 2; p <= n; p = p * 2)
	{
		for (i = 0; i + p -1 < n; i = i + p)
		{
			l = i;
			h = i + p - 1; 
			mid = (l + h) / 2; 
			merge(arr, l, mid, h);
		}
	}
	if (p/2 < n)
		merge(arr, 0, p/2-1, n-1);
}

int main(void)
{
	int arr[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
	int n = 10;

	i_merge_sort(arr, n);

	int i = 0;
	while (i < n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");

	return 0;
}