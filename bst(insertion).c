#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;
struct node{
    int data;
    Node *left,*right,*parent;
};
Node *create_node(int item){
    Node *new_node=(Node *)malloc(sizeof(Node));
    new_node->data=item;
    new_node->left=new_node->right=new_node->parent=NULL;

    return new_node;
}

void add_left_child(Node *node,Node *child){
    node->left=child;
    if(child!=NULL){
        child->parent=node;
    }
}
void add_right_child(Node *node,Node *child){
    node->right=child;
    if(child!=NULL){
        child->parent=node;
    }
}
Node * bst_insert(Node * root,Node *node){
    Node *parent_node,*current_node;
    while(root==NULL){
       root=node;
       return root;
    }
    parent_node=NULL;
    current_node=root;

    while(current_node!=NULL){
        parent_node=current_node;

        if(node->data < current_node->data){
            current_node=current_node->left;
        }
        else  current_node=current_node->right;
    }
    if(node->data < parent_node->data){
        add_left_child(parent_node,node);
    }
    else add_right_child(parent_node,node);

    return root;
}
Node *create_bst()
{
Node *root,*node;
int i,a[]={12,3,65,7,9};

root=create_node(10);

for(int i=0;i<5;i++){
        node=create_node(a[i]);
        root=bst_insert(root,node);
    }
    return root;
}
void inorder(Node* node)
{
    if (node->left != NULL) {
        inorder(node->left);
    }
        printf("%d ", node->data);

    if (node->right != NULL)
        inorder(node->right);

}
Node *bst_search(Node *root,int item){
    Node *node=root;
    while(node!=NULL){
        if(node->data==item)return node;
        if(node->data>item)node=node->left;
        else node=node->right;
    }
    return node;
}
Node *bst_minimum(Node *root){
    Node *node=root;
    while(node->left!=NULL){
        node=node->left;
    }
    return node;
}
Node *TransplantBySuccessor(Node *root,Node *current_node,Node *new_node){
    if(current_node==root)root=new_node;
    else if(current_node==current_node->parent->left)add_left_child(current_node->parent,new_node);//natike chhele bananu :3
    else add_right_child(current_node->parent,new_node);//natike chhele bananu :3
    return root;
}
Node *bst_deletion(Node *root,Node *node){
    Node *smallest_node;
    if(node->left==NULL)root=TransplantBySuccessor(root,node,node->right);
    else if(node->right==NULL)root=TransplantBySuccessor(root,node,node->left);
    else {
    smallest_node=bst_minimum(node->right);

    if(smallest_node->parent!=node){root=TransplantBySuccessor(root,smallest_node,smallest_node->right);
    add_right_child(smallest_node,node->right);
    }
    root=TransplantBySuccessor(root,node,smallest_node);
    add_left_child(smallest_node,node->left);
    }
    free(node);
    return root;
}
int main(){
    Node *root=create_bst();
    printf("After insertion:");
    inorder(root);
    int x;
    printf("\nwhich value do you wanna search?");
    scanf("%d",&x);
    Node *node=bst_search(root,x);
    if(node!=NULL)printf("Found");
    else printf("Not Found");

    printf("\nWhich value do you want to delete?");
    int y;
    scanf("%d",&y);
    node=bst_search(root,y);
    if(node==NULL)printf("Not Found");
    else {
       root=bst_deletion(root,node);

       printf("After Deletion:");
       inorder(root);
    }
}
