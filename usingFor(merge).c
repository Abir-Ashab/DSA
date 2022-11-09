#include <stdio.h>
#include <stdlib.h>


int mymergesort(int array[], int left, int right);

int main()
{
    int i;
    int arr[10];
    for(i=10;i>0;i--){
        arr[10-i]=i;
    }
    for(i=0;i<10;i++){
        printf("arr[%d] = %d\n",i,arr[i]);
        }

    mymergesort(arr,0,9);
    puts("\n");
    for(i=0;i<10;i++){
        printf("arr[%d] = %d\n",i,arr[i]);
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
    int arr_sorted[10];

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
