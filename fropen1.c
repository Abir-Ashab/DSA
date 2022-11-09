#include<stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node*next;
};


  struct node*head=0;

void create_node(int x){
    struct node*newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=x;
        newnode->next=0;
        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
               while((temp->next)!=0){
                 temp=newnode;
            }
        }


    }


void display_element(){
     struct node*temp;
     temp=head;
     while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->next;
     }
}
int main(){
    freopen("linkedList.txt","r",stdin);
    int x;

    while(scanf("%d",&x)!=EOF){;
    create_node(x);
    }
    display_element();

}
