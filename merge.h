//m: size of a, n: size of b
void merge(int a[], int b[], int c[], int m, int n)
{
	int i = 0, j = 0, k = 0;
	while(i < m && j < n)
	{
		if(a[i] < b[j])
		{
			c[k++] = a[i++];
		}
		else
		{
			c[k++] = b[j++];
		}
	}
	while(i < m)
	{
		c[k++] = a[i++];
	}
	while(j < n)
	{
		c[k++] = b[j++];
	}
}
