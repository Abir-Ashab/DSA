#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;   
};
void printLinkedlist(struct node *ptr){ 
    while(ptr!=NULL){
    printf("%d ",ptr->data);
    ptr=ptr->next;
    }
}
struct node * insertFirst(struct node *head,int data){
 struct node * ptr=(struct node *)malloc(sizeof(struct node));
 ptr->data=data;
 ptr->next=head;

return ptr;
}

struct node * insertLast(struct node *fourth,int data){
   struct node * ptr=(struct node *)malloc(sizeof(struct node));
   ptr->data=data;
   ptr->next=NULL;

   return ptr;
}
struct node * insertInindex(struct node *head,int data,int index){
    int i=0;
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    struct node * p=head;

   while (i!=index-1)
   {
    i++;
    p = p->next;
   }
  ptr->data=data;
  ptr->next = p->next;
  p->next=ptr;

  return ptr;
}
int main(){
    struct node *head,*second,*third,*fourth;
    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));

    head->data=30;
    head->next=second;

    second->data=1;
    second->next=third;

    third->data=32;
    third->next=fourth;

    fourth->data=10;
    fourth->next=NULL;

    printLinkedlist(head);

    head=insertFirst(head,4);
    printf("\nafter insertion at first:\n");
    printLinkedlist(head);

    fourth->next=insertLast(fourth,7);
    printf("\nafter insertion at last:\n");
    printLinkedlist(head);

    insertInindex(head,8,2);
    printf("\nafter insertion at index 2:\n");
    printLinkedlist(head);
}