#include<bits/stdc++.h>
using namespace std;
int gold_mine(int** arr, int n, int m)
{
int dp_table[n][m];
int x,ans,mans;
for(int i=0; i<n; i++)
dp_table[i][0]=arr[i][0];
for(int j=1; j<m; j++)
{
for(int i=0; i<n; i++)
{
if(i==0)
dp_table[i][j] = arr[i][j]+max(dp_table[i][j-1], dp_table[i+1][j-1]);
else if(i==n-1)
dp_table[i][j] = arr[i][j]+max(dp_table[i][j-1], dp_table[i-1][j-1]);
else
{
int mx = max(dp_table[i][j-1], dp_table[i-1][j-1]);
dp_table[i][j] = arr[i][j] + max(mx,dp_table[i+1][j-1]);
}
}
}
cout<<endl<<"DP Table Values --->"<<endl;
for(int i=0; i<n; i++)
{
for(int j=0; j<m; j++)
cout<<dp_table[i][j]<<" ";
cout<<endl;
}
mans = 0;
for(int i=0; i<n-1; i++)
{
ans = max(dp_table[i][m-1], dp_table[i+1][m-1]);
mans = max(ans,mans);
}
vector<int> pos;
for(int i=0; i<n-1; i++)
{
if(dp_table[i][m-1]==mans)
pos.push_back(i);
}
cout<<"Maximum amount of gold is at : ";
for(int i=0; i<pos.size(); i++)
cout<<"("<<pos[i]<<", "<<m-1<<")"<<" ";
cout<<endl;
return mans;
}
int main()
{
int n,m;
cout<<"Enter Number of Rows : ";
cin>>n;
cout<<"Enter Number of Columns : ";
cin>>m;
cout<<"Enter Costs : \n";
int** arr = (int**)(malloc(sizeof(int*) * n));
for(int i=0; i<n; i++)
{
arr[i] = (int*)(malloc(sizeof(int) * m));
for(int j=0; j<m; j++)
cin>>arr[i][j];
}
int a = gold_mine(arr,n,m);
cout<<"Maximum amount of gold we can collect : "<<a<<endl;
}
