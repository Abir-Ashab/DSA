#include<stdio.h>
#include<stdlib.h>
#define MAX_TREE_HT 150
struct node
{
    char data;
    int fr;
    struct node* left1;
    struct node* right1;
    struct node* left;
    struct node* right;
    struct node* parent;

} ;
int bst_size=0;
struct node * root=NULL;
struct node *newnode(char data,int fr)
{
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->fr=fr;
    temp->left=temp->right=temp->left1=temp->right1=temp->parent=NULL;
    return temp;
}
struct node * Extract_min(struct node* x)
{
    while(x->left!=NULL)
    {
        x=x->left;
    }
    return x;
}
struct node* Insert(struct node * z)
{
    struct node *y=NULL;
    struct node * x=root;

    while(x!=NULL)
    {
        y=x;
        if(z->fr<x->fr)
        {
            x=x->left;
        }
        else x=x->right;
    }
    z->parent=y;

    if(y==NULL)
    {
        root=z;
    }
    else if(z->fr<y->fr)
    {
        y->left=z;
    }
    else y->right=z;
    bst_size++;
    return root;

}
void inorder(struct node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d %c ", root->fr,root->data);
        inorder(root->right);
    }
}
struct node* search(struct node * x,int k)
{
    if (x==NULL || k==x->fr)
    {
        return x;
    }
    if(k<x->fr)
    {
        return search(x->left,k);
    }
    else return search(x->right,k);
};
struct node * successor(int val)
{
    struct node* x=search(root,val);
    if (x->right!=NULL)
    {
        return Extract_min(x->right);
    }
    struct node* y=x->parent;
    while(y!=NULL&&x==y->right)
    {
        x=y;
        y=y->parent;
    }
    return y;

}
void Tree_delete(struct node * z)
{   //printf("1234");
    struct node* y;
    struct node* x;

    if (z->left==NULL||z->right==NULL)
    {
        y=z;
    }
    else y=successor(z->fr);
    if(y->left!=NULL)
    {
        x=y->left;
    }
    else x=y->right;
    if(x!=NULL)
    {
        x->parent=y->parent;
    }
    if(y->parent==NULL)
    {
        root=x;
    }
    else if(y==y->parent->left)
    {
        y->parent->left=x;
    }
    else y->parent->right=x;
    if(y!=z)
    {
        z->fr=y->fr;
    }
    bst_size--;

};
int isLeaf(struct node* root1)

{

    return !(root1->left1) && !(root1->right1);
}
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i <n; ++i)
        printf("%d", arr[i]);

    printf("\n");
}
void printCodes(struct node* root1, int arr[],
                int top)

{

    if (root1->left1) {
        arr[top] = 0;
        printCodes(root1->left1, arr, top + 1);
    }

    if (root1->right1) {
        arr[top] = 1;
        printCodes(root1->right1, arr, top + 1);
    }

    if (isLeaf(root1)) {
        printf("%c: ", root1->data);
        printArr(arr, top);
    }

}

void HuffmanCodes()
{
    struct node* left,*right,*top;
    while (bst_size!=1) {

        left = Extract_min(root);
        Tree_delete(Extract_min(root));
        right = Extract_min(root);
        Tree_delete(Extract_min(root));

        top = newnode('#', left->fr + right->fr);

        top->left1 = left;
        top->right1 = right;


        Insert(top);
    }
    struct node* root1
        = Extract_min(root);
    int arr[MAX_TREE_HT], top1 = 0;
    printCodes(root1, arr, top1);
}
int main()
{

   freopen("huffman4.txt","r",stdin);
   int size,i;
   scanf("%d",&size);
   char arr[size+2];
    int freq[size+1];
    for(i=0;i<size;i++)
    {
        scanf("%d",&freq[i]);

    }
    getchar();
     for(i=0;i<size;i++)
    {
        scanf("%c",&arr[i]);
        getchar();

    }
    for(int i=0;i<size;i++){
        Insert(newnode(arr[i],freq[i]));
    }
    //size = sizeof(arr) / sizeof(arr[0]);
    HuffmanCodes();


    return 0;
}
/*
6
5 9 12 13 16 45
A B C D E F
*/
