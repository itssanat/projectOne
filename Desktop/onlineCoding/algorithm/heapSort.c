#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// heap sort function //

int parent(int i){
	return	i/2;
}

int leftChild(int i){
	return 2*i;
}

int rightChild(int i){
	return 2*i+1;
}

void Maxheapify(int arr[],int i,int n){   // maxHeapify // 
	int l = leftChild(i);
	int r = rightChild(i);
	int largest = i;
	if(l<n && arr[l]>arr[i])
		largest = l;
	if(r<n && arr[r]>arr[largest])
		largest = r;
	if(largest != i){
		int tmp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = tmp;
		Maxheapify(arr,largest,n);
	}
}

void heapsort(int arr[],int n){ /// heap sort function // 
	int i;
	for(i = n/2;i>0;i--){ //build heap (rearrange array) //
		Maxheapify(arr,i,n);
	}

	for(i = n-1;i>1;i--){
		int tmp = arr[1];
		arr[1] = arr[i];
		arr[i] = tmp;
		Maxheapify(arr,1,i);
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {-1,5,6,1,4,15,2,10,11,99,60}; // index start from 1//
	int n = 11;	   // arr[0] is considered is null ///
	heapsort(arr,n);
	int i;
	for (i = 1; i < n; ++i)
	{
		printf("%d ",arr[i]);
	}
	return 0; 
}