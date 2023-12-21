#include<bits/stdc++.h>
using namespace std;
int min_cost(int** arr, int n, int m)
{
    int dp_table[n][m];
    dp_table[0][0] = arr[0][0];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i==0 && j!=0)
                dp_table[i][j] = arr[i][j]+dp_table[i][j-1];
            else if(i!=0 && j==0)
                dp_table[i][j] = arr[i][j]+dp_table[i-1][j];
            else
            {
                dp_table[i][j] = arr[i][j] + min(dp_table[i][j-1], dp_table[i-1][j]);
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
    return dp_table[n-1][m-1];
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
    int ans = min_cost(arr,n,m);
    cout<<endl<<"Minimum Cost to Reach the Bottom-Right Cell from the Top-Left Cell is : "<<ans<<endl;
}
