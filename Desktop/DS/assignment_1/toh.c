#include<stdio.h>

void TOH(int n, char s,char a,char d){
	if(n==1){
		printf("%c--->>>%c\n",s,d);
		return ;
	}
	TOH(n-1,s,d,a);
	printf("%c--->>>%c\n",s,d);
	TOH(n-1,a,s,d);
}

int main(){
	int n;
	char s = 'A',a='B',d = 'C';
	printf("enter the number of disk:\n");
	scanf("%d",&n);
	TOH(n,s,a,d);
	return 0;
}