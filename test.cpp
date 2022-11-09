#include<bits/stdc++.h>
using namespace std;
int main()
{
long long int test,n;
cin>>test;
while(test--){
    cin>>n;
    long long x=log(n+1)/log(2);
    cout<<x<<endl;
}
return 0;
}
