#include<stdio.h>

int fact(int a){
	if(a == 1)
		return 1;
	return a*fact(a-1);
}

void main(){
	int a;
	printf("enter any number: \n");
	scanf("%d",&a);

	int f = fact(a);
	printf("factorial of %d = %d\n",a,f );
}