#include<stdio.h>
#define stack_max 10
typedef struct
{
    int top;
    int data[stack_max];
}stack;

int main(){
stack my_stack;
int item,x,y;

my_stack.top=0;
push(&my_stack,2);
push(&my_stack,34);
push(&my_stack,5);

pop(&my_stack);
printf("%d ",item);
pop(&my_stack);
printf("%d ",item);
pop(&my_stack);
printf("%d ",item);
}
int push(stack *s,int item){
    if(s->top<stack_max){
        s->data[s->top]=item;
        s->top++;
    }
    else printf("stack is full");
}
int pop(stack *s){
    int item;
    if(s->top==0)printf("stack is empty");
    else{
        s->top--;
        item=s->data[s->top];
    }
    return item;
}
