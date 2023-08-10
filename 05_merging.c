

void merge(int arr1[], int arr2[b], int m, int m)
{
	int i, j, k;
	i = j = k = 0;

	while (i < m && j < n)
	{
		if (arr1[i] < arr2[j])
		{
			sol[k] = arr1[i];
			k++;
			i++;
		}
		else 
		{
			sol[k] = arr2[j];
			k++;
			j++;
		}
	}
	while (i < m)
	{
		sol[k] = arr1[i];
		k++;
		i++;
	}
	while (j < n)
	{
		sol[k] = arr2[j];
		k++;
		j++;
	}
}