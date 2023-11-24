#include<bits/stdc++.h>
using namespace std;

bool subset_sum(int n,int arr[],int sum)
{
    int include,exclude;
    bool table[n+1][sum+1];

    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<sum+1; j++)
        {
            if(i==0)
            {
                if(j==0) table[i][j]=1;
                else table[0][j]=0;
            }
            else
            {
                include=table[i-1][j];
                if(j-arr[i-1]<0) exclude=0;
                else exclude=table[i-1][j-arr[i-1]];

                table[i][j]=include | exclude;
            }
        }
    }
    cout<<"Table ---> "<<endl;
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<sum+1; j++)
        {
            if(table[i][j]==1) cout<<"T"<<" ";
            else cout<<"F"<<" ";
        }
               cout<<endl;
    }
    return table[n][sum];
}

int main()
{
    int arr[] = {2,3};
    int sum;
    cout<<"Enter the value of sum : ";
    cin>>sum;
    int n = sizeof(arr)/sizeof(arr[0]);
    bool ans = subset_sum(n,arr,sum);
    cout<<endl;
    if(ans==1) cout<<"Yes, it's possible."<<endl;
    else cout<<"No, it's not possible."<<endl;
}


