#include<stdio.h>

void inssort(int a[], int n)
{
	int i=0,t,j;
	for (i = 1; i < n; ++i)
	{
		t=a[i];
		for (j = i-1; j>=0 && a[j]>t ; j--)
			a[j+1]=a[j];

		a[j+1]=t;
	}
}

void main()
{
	int n,i;
	scanf("%d",&n);

	int a[n];
	for (i = 0; i < n; ++i)
		scanf("%d",&a[i]);

	inssort(a,n);

	for (i = 0; i < n; ++i)
		printf("%d ",a[i]);
}