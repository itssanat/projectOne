#include<stdio.h>
int s[100],top = -1;

void func(int n)
{
	int i=2;
	while(n != 1)
	{
		while(n%i == 0)
		{
			s[++top]  = i;
			n/=i;
		}
		i++;
	}

	while(top != -1){
		printf("%d\n",s[top--]);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	func(n);
	return 0;
}