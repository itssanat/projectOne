#include<stdio.h>

int partition(int a[], int l, int h)
{
	int piv=a[l];
	int i=l;
	int j=h+1;
	int t;

	do{
		do{
			i++;
		}while(i<=h && piv>a[i]);

		do{
			j--;
		}while(piv<a[j]);

		if(i<j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}while(i<j);

	a[l]=a[j];
	a[j]=piv;
	
	return j;
}

void quick_sort(int a[], int l, int h)
{
	if(l<h)
	{
		int k= partition(a,l,h);

		quick_sort(a,l,k-1);
		quick_sort(a,k+1,h);
	}
}

void main()
{
	int i,n;
	scanf("%d",&n);
	int a[n+2];
	for (i = 0; i < n; i++)
		scanf("%d",&a[i]);
	quick_sort(a,0,n-1);
	for (i = 0; i < n; ++i)
		printf("%d ",a[i]);
}