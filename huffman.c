#include <stdio.h>
#include <stdlib.h>

typedef struct minHeapNode MNode;
typedef struct minHeap MinHeap;

 struct minHeapNode{
	char data;
	unsigned freq;
	MNode *left, *right;
};
 struct minHeap{
	unsigned size;
	unsigned capacity;
	MNode** array;
};
MNode* newNode(char data, unsigned freq){

	MNode* temp = (MNode*)malloc(sizeof(MNode));

	temp->left = temp->right = NULL;
	temp->data = data;
	temp->freq = freq;

	return temp;
}
MinHeap* createMinHeap(unsigned capacity){
	MinHeap* minHeap= (MinHeap*)malloc(sizeof(MinHeap));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (MNode**)malloc(minHeap->capacity * sizeof(MNode*));
	return minHeap;
}
void swapMinHeapNode(MNode** a,MNode** b){
	MNode* t = *a;
	*a = *b;
	*b = t;
}

void minHeapify(MinHeap* minHeap, int idx){
	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < minHeap->size
		&& minHeap->array[left]->freq
			< minHeap->array[smallest]->freq)
		smallest = left;

	if (right < minHeap->size
		&& minHeap->array[right]->freq
			< minHeap->array[smallest]->freq)
		smallest = right;

	if (smallest != idx) {
		swapMinHeapNode(&minHeap->array[smallest],
						&minHeap->array[idx]);
		minHeapify(minHeap, smallest);
	}
}
int isSizeOne(MinHeap* minHeap)
{

	return (minHeap->size == 1);
}
MNode* extractMin(MinHeap* minHeap){
	MNode* temp = minHeap->array[0];
	minHeap->array[0] = minHeap->array[minHeap->size - 1];

	--minHeap->size;
	minHeapify(minHeap, 0);

	return temp;
}
void insertMinHeap(MinHeap* minHeap,
				MNode* minHeapNode){
	++minHeap->size;
	int i = minHeap->size - 1;

	while (i
		&& minHeapNode->freq
				< minHeap->array[(i - 1) / 2]->freq) {

		minHeap->array[i] = minHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}

	minHeap->array[i] = minHeapNode;
}
void buildMinHeap(MinHeap* minHeap){
	int n = minHeap->size - 1;
	int i;

	for (i = (n - 1) / 2; i >= 0; --i)
		minHeapify(minHeap, i);
}
void printArr(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		printf("%d", arr[i]);

	printf("\n");
}
int isLeaf(MNode* root){
	return !(root->left) && !(root->right);
}
MinHeap* createAndBuildMinHeap(char data[],int freq[], int size){
	MinHeap* minHeap = createMinHeap(size);

	for (int i = 0; i < size; ++i)
		minHeap->array[i] = newNode(data[i], freq[i]);

	minHeap->size = size;
	buildMinHeap(minHeap);
	return minHeap;
}
MNode* buildHuffmanTree(char data[],int freq[], int size){
	MNode *left, *right, *top;
	MinHeap* minHeap=createAndBuildMinHeap(data, freq, size);
	while (!isSizeOne(minHeap)) {
		left = extractMin(minHeap);
		right = extractMin(minHeap);
		top = newNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
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
	MNode* root= buildHuffmanTree(data, freq, size);
	int arr[1000], top = 0;

	printCodes(root, arr, top);
}
int main()
{
	freopen("data.txt","r",stdin);
	//gets(arr);
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
