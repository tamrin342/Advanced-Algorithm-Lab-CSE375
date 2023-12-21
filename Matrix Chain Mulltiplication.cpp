#include<bits/stdc++.h>
using namespace std;
int matrixchain_multiplication(int n, int arr[])
{
int res,val,mn,j;
int m_table[n][n];
for(int l=1; l<n; l++)
{
for(int i=1; i<=n-l; i++)
{
j=i+l-1;
if(i==j) m_table[i][j]=0;
else
{
val = INT_MAX;
for(int k=i; k<j; k++)
{
res = m_table[i][k] + m_table[k+1][j] + (arr[i-1]*arr[k]*arr[j]);
val = min(val,res);
}
m_table[i][j]=val;
}
}
}
int cnt;
for(int i=1; i<n; i++)
{
if(i>1)
{
cnt = 3*(i-1);
while(cnt!=0)
{
cout<<" ";
cnt--;
}
}
for(int j=1; j<n; j++)
{
if(j>=i) cout<<m_table[i][j]<<" ";
else cout<<" ";
}
cout<<endl;
}
return m_table[1][n-1];
}
int main()
{
cout<<"Enter the size of the array : ";
int n;
cin>>n;
int arr[n];
cout<<"Enter the values : ";
for(int i=0; i<n; i++)
cin>>arr[i];
int ans = matrixchain_multiplication(n,arr);
cout<<"Minimum number of scaler operation needed is "<<ans;
}
