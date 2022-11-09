#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,t,a[100000],c=0;
cin>>n>>t;
for(int i=0;i<n-1;i++){
    cin>>a[i];
}
for(int i=0;i<n-1;i+=a[i]){
    if((i+1)==t)c++;
}
if(c!=0)cout<<"YES";
else cout<<"NO";
}
