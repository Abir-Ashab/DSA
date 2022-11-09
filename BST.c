#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    int data;
    Node* leftchild,*rightchild,*parent;
};
Node *root=NULL;
//node tar address allocate kore dan bam NULL kore dey
Node *newnode(int item){
    Node * temp=(Node*)malloc(sizeof(Node));
    temp->data=item;
    temp->leftchild=temp->rightchild=temp->parent=NULL;
    return temp;
}

Node* Extract_Min(Node* x){
    while(x->leftchild!=NULL){
        x=x->leftchild;
    }
    return x;
};
Node* bst_insert(Node * root,int key){
    Node* y=NULL;
    Node* x=root;
    Node* current=newnode(key);
    while(x!=NULL){//find parent node
        y=x;
        if(current->data > x->data){
            x=x->rightchild;
        }
        else x=x->leftchild;
    }
    current->parent=y;

    if(y==NULL){
        root=current;
    }
    //replacement
    else if(current->data < y->data){
        y->leftchild=current;
    }
    else y->rightchild=current;
    return root;

}
void inorder(Node* root)
{
    if (root != NULL) {
        inorder(root->leftchild);
        printf("%d ", root->data);
        inorder(root->rightchild);
    }
}
Node* bst_search(Node * x,int k){
    if (x==NULL || k==x->data){
        return x;
    }
    if(k<x->data){
        return bst_search(x->leftchild,k);
    }
    else return bst_search(x->rightchild,k);
}
Node * bst_successor(int val){
    Node* x=bst_search(root,val);
    if (x->rightchild!=NULL)return Extract_Min(x->rightchild);

    Node* y=x->parent;
    while(y!=NULL&&x==y->rightchild){
        x=y;
        y=y->parent;
    }
    return y;

}
void bst_delete(int key){
   Node* z=bst_search(root,key);
    Node* y;
    Node* x;

    if (z->leftchild==NULL||z->rightchild==NULL){
        y=z;
    }
    else y=bst_successor(z->data);
    if(y->leftchild!=NULL){
        x=y->leftchild;
    }
    else x=y->rightchild;
    if(x!=NULL){
        x->parent=y->parent;
    }
    if(y->parent==NULL){
        root=x;
    }
    else if(y==y->parent->leftchild){
        y->parent->leftchild=x;
    }
    else y->parent->rightchild=x;
    if(y!=z){
        z->data=y->data;
    }

};
int main(){
    int n;
    freopen("info.txt","r",stdin);
    printf("Number of elements:\n");
    scanf("%d",&n);

    int r;
    printf("initial root:\n");
    scanf("%d",&r);
    root=bst_insert(root,r);
    printf("Other elements of BST:\n");
    for(int i=1;i<n;i++){
        int x;
        scanf("%d",&x);
        bst_insert(root,x);
    }

    printf("Sortred order:\n");
    inorder(root);
    //printf("\n");

    printf("\nwhich value do you wanna search?\n");
    int a;
    scanf("%d",&a);
    Node* search=bst_search(root,a);
    if(search==NULL){
        printf("%d is not found\n",a);
    }
    else
    printf("%d is found\n",a);

    printf("For which value do you want its successor?\n");
    scanf("%d",&a);
    Node * success=bst_successor(a);
    printf("successor of %d is -> %d\n",a,success->data);

    printf("which value do you wanna delete?\n");
    int b;
    scanf("%d",&b);
    bst_delete(b);
    printf("After deletion:\n");
    inorder(root);
}
/*Node* Extract_Max(Node* x){
    while(x->rightchild!=NULL){
        x=x->rightchild;
    }
    return x;
};*/

//Node* max=Extract_max(root);printf("Maximum value is %d\n",max->data);max value print hobe
