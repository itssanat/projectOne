#include<stdio.h>
#include<stdlib.h>

#define strSize 100
struct stack {
    int arr[strSize];
    int top;
};
typedef struct stack STACK;

void push(STACK *s){
    int x;
    if(s->top == strSize-1){
        printf("stack Overflow.\n");
    } else {
        printf("enter your number to push:");
        scanf("%d",&x);
        s->arr[++s->top]=x;
    }
}

void pop(STACK *s){
    if(s->top==-1)
        printf("stack underflow.\n");
    else{
        printf("poped element: %d\n",s->arr[s->top]);
        s->top--;
    }
}

void display(STACK *s){
    int i=0;
    for(i=0;i<=s->top;i++){
        printf("%d   ",s->arr[i]);
    }
    printf("\n");
}

void main(){
    STACK s;
    s.top =-1;
    int x;

    while(1){
        printf("enter 1 to push element in stack.\n");
        printf("enter 2 to pop element.\n");
        printf("enter 3 to display stack.\n");
        printf("enter 5 to exit\n");

        scanf("%d",&x);
        switch(x){
            case 1:
            push(&s);
            break;
            case 2:
            pop(&s);
            break;
            case 3:
            display(&s);
            break;
            case 5:
            exit(1);
            default :
            printf("please enter a valid choice.\n");

        }
    }

}