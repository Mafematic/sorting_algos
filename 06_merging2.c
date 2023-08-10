void merge(int arr1[], int l, int mid, int h)
{
	int i, j, k;
	int arr2[h+1];
	i = l, j = mid + 1, k = l
	i = j = k = 0;

	while (i <= mid && j <= h)
	{
		if (arr1[i] < arr1[j])
		{
			sol[k] = arr1[i];
			k++;
			i++;
		}
		else 
		{
			sol[k] = arr1[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		sol[k] = arr1[i];
		k++;
		i++;
	}
	while (j <= h)
	{
		sol[k] = arr1[j];
		k++;
		j++;
	}
	i = l;
	while (i <= h)
	{
		arr1[i] = sol[i];
		i++
	}
}