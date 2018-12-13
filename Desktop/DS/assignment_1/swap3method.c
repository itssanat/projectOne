#include<stdio.h>

void main(){
	int a,b;
	printf("enter the first number: ");
	scanf("%d",&a);
	printf("enter the second number: ");
	scanf("%d",&b);

	// swap using third variable
	int tmp = a;
	a = b;
	b= tmp;
	printf("swap using third variable:\n");
	printf("a = %d\nb = %d\n",a,b);

	//swap without using third variable
	a = a +b;
	b = a-b;
	a = a-b;
	printf("swap without using third variable:\n");
	printf("a = %d\nb = %d\n",a,b);

	//swap using xor operator 
	a^=b^=a^=b;
	printf("swap using XOR operator:\n");
	printf("a = %d\nb = %d\n",a,b);
}