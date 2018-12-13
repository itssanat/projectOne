#include <stdio.h>

void callByValue(int a ,int b){
	a = a+b;
	b = a-b;
	a =a-b;
	printf("In call by value function.\n");
	printf("fist number: %d",a);
	printf("\nSecond number: %d\n",b);
	// but acctual value remain unaffected.
	// only copy of the number is swapped by this method
}

void callByReference(int *a,int *b){
	*a = *a+*b;
	*b = *a-*b;
	*a = *a - *b;
}

void main(){
	int a, b;
	printf("enter first number a:\n");
	scanf("%d",&a);
	printf("enter second number b:\n");
	scanf("%d",&b);

	callByValue(a,b);
	printf("\nvalue of a and b after call by value: %d and %d\n",a,b);

	callByReference(&a,&b);
	printf("\nvalue of a and b after call by reference: %d and %d\n",a,b);

}