#include <stdio.h>
#include <stdlib.h>
int num;

int mymergesort(int array[], int left, int right);

int main()
{
    int i;
    
    scanf("%d",&num);
    int arr[num];
    for(i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    mymergesort(arr,0,num-1);
    puts("\n");
    printf("sorted array:");
    for(i=0;i<num;i++){
        printf("%d ",arr[i]);
        }
    return 0;
}

int mymergesort(int array[], int left, int right)
{
    int mymerge(int array[],int left, int mid, int right);
    int mid;

    mid=(left+right)/2;
    if(left<right){
        mymergesort(array,left,mid);
        mymergesort(array,mid+1,right);
        mymerge(array,left,mid,right);
    }
    return 0;
}

int mymerge(int array[], int left, int mid, int right)
{
    int i=0;
    int l=left;
    int r=mid+1;
    int arr_sorted[num];

    for(i=left;i<=right;){
        if((l<=mid) && (r<=right)){
            if(array[l]<array[r]){
                arr_sorted[i]=array[l];
                l++;
                i++;

            }
            else {
                arr_sorted[i]=array[r];
                r++;
                i++;
            }
        }

        if(l>mid){
            for(;r<=right;r++){   
                arr_sorted[i]=array[r];
                i++;

            }   
            break;
        }
        if(r>right){
            for(;l<=mid;l++){

                 arr_sorted[i]=array[l];
                    i++; 
            }
            break;
        }
    }
    for(i=left;i<=right;i++){
        array[i]=arr_sorted[i];
    }
}