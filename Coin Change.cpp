#include<bits/stdc++.h>
using namespace std;
int coin_change(int n,int arr[],int val)
{
int a,b;
int table[n+1][val+1];
for(int i=0; i<n+1; i++)
{
for(int j=0; j<val+1; j++)
{
if(i==0)
{
if(j==0) table[i][j]=1;
else table[0][j]=0;
}
else
{
a=table[i-1][j];
if(j-arr[i-1]<0) b=0;
else b=table[i][j-arr[i-1]];
table[i][j]=a+b;
}
}
}
cout<<"Table ---> "<<endl;
for(int i=0; i<n+1; i++)
{
for(int j=0; j<val+1; j++)
cout<<table[i][j]<<" ";
cout<<endl;
}
return table[n][val];
}
int main()
{
int arr[] = {1,2,3,5};
int val = 7;
int n = sizeof(arr)/sizeof(arr[0]);
int ans = coin_change(n,arr,val);
cout<<endl;
cout<<"ways of coin change : "<< ans<<endl;
}


