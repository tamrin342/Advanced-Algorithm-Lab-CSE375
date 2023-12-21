#include<bits/stdc++.h>
using namespace std;
int path_count(int n, int m)
{
    int arr[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i==0 || j==0)
                arr[i][j]=1;
            else
                arr[i][j]=arr[i-1][j]+arr[i][j-1];
        }
    }
    cout<<endl<<"Table --->"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    return arr[n-1][m-1];
}
int main()
{
    int row,col;
    cout<<"Enter the number of rows : ";
    cin>>row;
    cout<<"Enter the number of columns : ";
    cin>>col;
    int ans = path_count(row,col);
    cout<<endl<<"Total Path : "<<ans<<endl;
}
