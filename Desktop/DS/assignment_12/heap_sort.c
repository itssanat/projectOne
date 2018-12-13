#include<stdio.h>
int size;

void heapify(int a[], int p)
{
	int left = 2*p;
	int right = 2*p+1;
	int t = 0;
	while(right <= size)
	{
		
		if(left==size)
		{
			t=a[p];
			a[p]=a[left];
			a[left]=t;
		}

		else if(a[p] >= a[left] && a[p] >= a[right])
			return;

		else if(a[left] > a[right])
		{
			t=a[p];
			a[p]=a[left];
			a[left]=t;

			p=left;
		}
	
		else
		{
			t=a[p];
			a[p]=a[right];
			a[right]=t;

			p=right;
		}

		left = 2*p;
		right = 2*p+1;
	}

	if(left == size && a[p]<a[left])
	{
		t=a[p];
		a[p]=a[left];
		a[left]=t;
	}
}

void build_heap(int a[])
{
	int i;
	for (i=size/2; i >=1; i--) 
		heapify(a,i);
}

void heap_sort(int a[])
{
	int i=1,p;
	do{
		p=a[i];
		a[i]=a[size];
		
		printf("%d ",p);
		size--;

		if(size > 0)
			heapify(a, i);
	
	}while(size!=0);
}

void main()
{
	int a[20];
	int n,i;
	scanf("%d",&n);
	size = n;

	for (i = 1; i <= n; ++i)
		scanf("%d",&a[i]);

	build_heap(a);

	heap_sort(a);
	/*for (i = 1; i <= n; ++i)
		printf("%d ",a[i]);
	printf("\n");*/
}