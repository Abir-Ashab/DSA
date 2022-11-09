#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define nl printf("\n");

typedef struct node
{
  int frequency;
  char data;
  struct node *left;
  struct node *right;
}node;

int heap_array_size = 100;
int heap_size = 0;
const int INF = 100000;

void swap( node *a, node *b ) {
  node t;
  t = *a;
  *a = *b;
  *b = t;
}

void inorder(struct node *root)
{
  if(root!=NULL)
  {
    inorder(root->left);
    printf(" %d ", root->frequency);
    inorder(root->right);
  }
}

node* new_node(char data, int freq) {
  node *p;
  p = (node*)malloc(sizeof(struct node));
  p->data = data;
  p->frequency = freq;
  p->left = NULL;
  p->right = NULL;

  return p;
}

int get_right_child(int index) {
  if((((2*index)+1) <= heap_size) && (index >= 1))
    return (2*index)+1;
  return -1;
}

int get_left_child(int index) {
    if(((2*index) <= heap_size) && (index >= 1))
        return 2*index;
    return -1;
}

int get_parent(int index) {
  if ((index > 1) && (index <= heap_size)) {
    return index/2;
  }
  return -1;
}

void insert(node A[], node* a, int key) {
  heap_size++;
  A[heap_size] = *a;
  int index = heap_size;
  while((index>1) && (A[get_parent(index)].frequency < a->frequency))       // using < instead of >
  {
    swap(&A[index], &A[get_parent(index)]);
    index = get_parent(index);
  }
}

node* build_queue(node c[], int size) {
  node* a = malloc(sizeof(node)*heap_array_size);
  int i;
  for(i=0; i<size; i++) {
    insert(a, &c[i], c[i].frequency);
  }
  return a;
}

void min_heapify(node A[], int index) {
  int left_child_index = get_left_child(index);
  int right_child_index = get_right_child(index);

  int smallest = index;

  if ((left_child_index <= heap_size) && (left_child_index>0)) {
    if (A[left_child_index].frequency < A[smallest].frequency) {
      smallest = left_child_index;
    }
  }

  if ((right_child_index <= heap_size && (right_child_index>0))) {
    if (A[right_child_index].frequency < A[smallest].frequency) {
      smallest = right_child_index;
    }
  }

  if (smallest != index) {
    swap(&A[index], &A[smallest]);
    min_heapify(A, smallest);
  }
}

node* extract_min(node A[]) {

    int i = 1;

    while(i < heap_size)
        i *= 2;             // searching for min_index
    node minm = A[i];
    A[i] = A[heap_size];
    heap_size--;
    min_heapify(A, 1);

    node *z;
    z = malloc(sizeof(struct node));
    z->data = minm.data;
    z->frequency = minm.frequency;
    z->left = minm.left;
    z->right = minm.right;
    return z;
}

node* greedy_huffman_code(node C[], int nonEmpty) {
  node *min_queue = build_queue(C, nonEmpty);

  while(heap_size > 1) {
    node *h = extract_min(min_queue);
    node *i = extract_min(min_queue);
    node *z;
    z = malloc(sizeof(node));
    z->data = '\0';
    z->left = h;
    z->right = i;
    z->frequency = z->left->frequency + z->right->frequency;
    insert(min_queue, z, z->frequency);
  }
  return extract_min(min_queue);
}

void printCode(int array[], int step)
{
    for(int i=0; i<step; ++i)
    {
        printf("%d", array[i]);
    }

    printf("\n");
}

void genPrefixCode(node* root, int array[], int step)
{
    if(root->left != NULL)
    {
        array[step] = 0;
        genPrefixCode(root->left, array, ++step);
    }

    if(root->right != NULL)
    {
        array[step] = 1;
        genPrefixCode(root->right, array, ++step);
    }

    if((root->left == NULL) && (root->right == NULL))
    {
        printf("%c: ", root->data);
        printCode(array, step);
    }
}

int main()
{
    char string[100];
    printf("Enter string: ");

    freopen("input.txt", "r", stdin);
    gets(string);

    int arrayint[26] = {0};
    char arraychar[26];
    int nonEmpty = 0;

    arraychar[0] = 'a';
    for(int i=1; i<26; ++i)
    {
        arraychar[i] = arraychar[i-1] + 1;
    }

    printf("\n");

    for(int i=0; string[i] != '\0'; ++i)
    {
        if(string[i] >= 'a'  &&  string[i]<='z')
           ++arrayint[string[i]-97];
    }

    for(int i=0; i<26; ++i)
    {
        if(arrayint[i] > 0)
            ++nonEmpty;
    }

    node C[nonEmpty];
    int j = 0;

    for(int i=0; i<26; ++i)
    {
        if(arrayint[i] > 0 && j < nonEmpty)
        {
            node *ptr = new_node(arraychar[i], arrayint[i]);
            C[j++] = *ptr;
        }
    }

    printf("\n");

    node* z = greedy_huffman_code(C, nonEmpty);

    printf("\n");

    int array[100];

    genPrefixCode(z, array, 0);

    return 0;
}
