#include<bits/stdc++.h>
using namespace std;

int Path_Count(int r, int c)
{
    int table[r][c];

    for(int i=r-1; i>=0; i--)
    {
        for(int j=c-1; j>=0; j--)
        {
            if(i==r-1 || j==c-1)
                table[i][j] = 1;
            else if(i%2==1)
                table[i][j]=  table[i][j+1] +  table[i+1][j];
            else
                table[i][j]=  table[i][j+1] +  table[i+1][j] + table[i+1][j+1];
        }
    }
    cout<<"PATH count  -->"<<endl;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
            cout<<table[i][j]<<" ";
        cout<<endl;
    }

    return table[0][0];
}

int Calc_Min_Cost(int **arr, int r, int c)
{
    int table[r][c];

    for(int i=r-1; i>=0; i--)
    {
        for(int j=c-1; j>=0; j--)
        {
            if(i==r-1 && j==c-1)
                table[i][j]= arr[i][j];
            else if(i==r-1 && j!=c-1)
                table[i][j]=  arr[i][j] +  table[i][j+1];
            else if(j==c-1 && i!=r-1)
                table[i][j]=  arr[i][j] +  table[i+1][j];
            else if(i%2==1)
                table[i][j]= arr[i][j] + min(table[i][j+1], table[i+1][j]);
            else
            {
                int mn = min(table[i][j+1], table[i+1][j]);
                table[i][j]= arr[i][j] + min(mn, table[i+1][j+1]);
            }
        }
    }

    cout<<"Minimum  -->"<<endl;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
            cout<<table[i][j]<<" ";
        cout<<endl;
    }
    return table[0][0];
}

int Calc_Max_Cost(int **arr, int r, int c)
{
    int table[r][c];

    for(int i=r-1; i>=0; i--)
    {
        for(int j=c-1; j>=0; j--)
        {
            if(i==r-1 && j==c-1)
                table[i][j]= arr[i][j];
            else if(i==r-1 && j!=c-1)
                table[i][j]=  arr[i][j] +  table[i][j+1];
            else if(j==c-1 && i!=r-1)
                table[i][j]=  arr[i][j] +  table[i+1][j];
            else if(i%2==1)
                table[i][j]= arr[i][j] + max(table[i][j+1], table[i+1][j]);
            else
            {
                int mx = max(table[i][j+1], table[i+1][j]);
                table[i][j]= arr[i][j] + max(mx, table[i+1][j+1]);
            }
        }
    }

    cout<<"Minimum  -->"<<endl;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
            cout<<table[i][j]<<" ";
        cout<<endl;
    }
    return table[0][0];
}

int main()
{
    int r,c;
    cin>>r>>c;
    int **arr = (int**)(malloc(sizeof(int**)*r));

    for(int i=0; i<r; i++)
    {
        arr[i] = (int*)(malloc(sizeof(int)*c));
        for(int j=0; j<c; j++)
            cin>>arr[i][j];
    }
    int ans1 = Path_Count(r,c);
    int ans2 = Calc_Min_Cost(arr,r,c);
    int ans3 = Calc_Max_Cost(arr,r,c);
    cout<<"Path count : "<<ans1<<endl;
    cout<<"Minimum Value : "<<ans2<<endl;
    cout<<"Maximum Value : "<<ans3<<endl;
}
