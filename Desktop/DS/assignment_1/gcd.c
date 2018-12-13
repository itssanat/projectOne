#include<stdio.h>

int gcd(int a ,int b){  //gcd using recursion
	if(b==0)
		return a;
	return gcd(b,a%b);
}

void main(){
	int a,b;
	printf("enter first number: \n");
	scanf("%d",&a);
	printf("enter second number: \n");
	scanf("%d",&b);

	int f = gcd(a,b);
	printf("gcd = %d\n",f );
}