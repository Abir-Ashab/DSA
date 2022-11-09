#include <stdio.h>

int fibbonacci(int n) {
   if(n == 0) {
      return 0;
   } else if(n == 1) {
      return 1;
   } else {
      return (fibbonacci(n-1) + fibbonacci(n-2));
   }
}

int main() {
   int a[10000];
	
   for(int i = 0,j=0;i<=42;i++) {
    int x=fibbonacci(i);
    a[j]=x;
    j++;
   }
   int m=20;
   while(m--){
   printf("enter kth number:");
   int k;
   scanf("%d",&k);
   if(k==0)a[0]=0;
   printf("%dth fibonacci number:%d\n",k,a[k]);
   }
}
