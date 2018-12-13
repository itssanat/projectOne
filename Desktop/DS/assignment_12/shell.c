#include <stdio.h> 

int shellSort(int arr[], int n) 
{ 
	int g,i; 
	for (g = n/2; g > 0; g /= 2) 
	{
		for (i = g; i < n; i++) 
		{
			int temp = arr[i]; 
			int j;	 
			for (j = i; j >= g && arr[j - g] > temp; j -= g) 
				arr[j] = arr[j - g];
			arr[j] = temp; 
		} 
	} 
	return 0; 
} 

int main() 
{ 
	int i,n;
	printf("enter number of elements:\n");
	scanf("%d",&n);
	int arr[n];
	printf("enter element:\n");
	for (i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	shellSort(arr, n); 
	printf("after sorting....\n");
	for (i=0; i<n; i++) 
		printf("%d  ",arr[i]);
	printf("\n");

	return 0; 
} 
