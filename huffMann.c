#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE_HT 150

typedef struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
}MNode;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    MNode** array;
}Mheap;

MNode* newNode(char data, unsigned freq){
    MNode* temp = (MNode*)malloc(sizeof(MNode));

    temp->left = NULL;
    temp->right =NULL;
    temp->data = data;
    temp->freq = freq;

    return temp;
}
Mheap* createMinHeap(unsigned capacity){

    Mheap* minHeap = (Mheap*)malloc(sizeof(Mheap));
    minHeap->size = 1;

    minHeap->capacity = capacity;

    minHeap->array = (MNode**)malloc(minHeap->capacity * sizeof(MNode*));
    return minHeap;
}

void swapMinHeapNode(MNode** a, MNode** b){

    MNode* t = *a;
    *a = *b;
    *b = t;
}
void minHeapify(Mheap* minHeap, int i){//recursive call diye mean heap banay

    int smallest = i;
    int left = 2 * i ;
    int right = 2 * i + 1;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != i) {
        swapMinHeapNode(&minHeap->array[smallest],&minHeap->array[i]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(Mheap* minHeap){
    return (minHeap->size == 1);
}
MNode* extractMin(Mheap* minHeap){

    MNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    minHeap->size --;
    minHeapify(minHeap, 0);

    return temp;
}

void insertMinHeap(Mheap* minHeap,MNode* minHeapNode){//min heap e new node insert kore
    //initially size was 6-2=4 (2 for 2 times extracting)
    ++ minHeap->size;
    int i = minHeap->size-1;

    while (i && minHeapNode->freq < minHeap->array[(i) / 2]->freq) {//mane new node ta jotokkhon small totokhn cholbe

        minHeap->array[i] = minHeap->array[(i) / 2];
        i = (i) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(Mheap* minHeap)

{

    int n = minHeap->size - 1;
    int i;

    for (i = (n) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);

    printf("\n");
}
int isLeaf(MNode* root)

{

    return !(root->left) && !(root->right);
}
    Mheap* createAndBuildMinHeap(char data[],int freq[], int size){
    Mheap* minHeap = createMinHeap(size);
    int i;
    for ( i = 0; i < size; ++i)minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

MNode* buildHuffmanTree(char data[],int freq[], int size){
    MNode *leftt, *rightt, *top;
    Mheap* minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)) {//untill the size is one

        leftt = extractMin(minHeap);//smallest ta anbe
        rightt = extractMin(minHeap);//ager smallest jawar por jeta smallest oita anbe

        top = newNode('h', leftt->freq + rightt->freq);

        top->left = leftt;
        top->right = rightt;

        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}
void printCodes(MNode* root, int arr[],int top){
    if (root->left) {

        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {

        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root)) {

        printf("%c: ", root->data);
        printArr(arr, top);
    }
}
void HuffmanCodes(char data[], int freq[], int size){

    MNode* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;

    printCodes(root, arr, top);
}

int main()
{
    freopen("data.txt","r",stdin);

	int size;
	scanf("%d",&size);

    char arr[size+1];
	int freq[size];
    getchar();
    for(int i=0;i<size;i++){
		scanf("%c",&arr[i]);
    }
	getchar();
	for(int i=0;i<size;i++){
		scanf("%d",&freq[i]);
    }

    HuffmanCodes(arr, freq, size);

    return 0;
}
