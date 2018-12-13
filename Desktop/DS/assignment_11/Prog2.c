#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool arr[101];

void insert(int num){
	arr[num] = true;
}

void isPresent(int num){
	if(arr[num])
		printf("number is present...\n");
	else
		printf("number is not present...\n");
}

int main(int argc, char const *argv[])
{
	int num,x,i;
	printf("1. to enter a number\n");
	printf("2. to check whether a number is present or not\n");
	printf("3. to exit\n");
	for(i= 0;i<=100;i++) arr[i] = false;
	while(true){
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("enter number\n");
				scanf("%d",&num);
				insert(num);
				break;
			case 2:
				printf("enter info\n");
				scanf("%d",&num);
				isPresent(num);
				break;
			case 3:
				exit(0);
			delete:
				printf("invalid input...\n");
		}
	}
	return 0;
}