#include<bits/stdc++.h>
using namespace std;

int Path_Count(int row, int col)
{
    int i, j ;
    int matrix[row][col], mntable[row][col], mxtable[row][col] ;

    for(i=0; i<row; i++)
    {
        for(j=col-1; j>=0; j--)
        {
            if(i==0 || j==col-1)
                matrix[i][j] = 1 ;

            else if (i%2!=0)
                matrix[i][j] = matrix[i-1][j] + matrix[i][j+1] ;

            else
                matrix[i][j] = matrix[i-1][j] + matrix[i][j+1] + matrix[i-1][j+1] ;

        }
    }

    return matrix[row-1][0] ;
}

int Calc_Min_Cost(int **arr, int row, int col)
{
    int dptable[row][col] , i, j ;

    for(i=0; i<row; i++)
    {
        for(j=col-1; j>=0; j--)
        {
            if(i==0 && j==col-1)
                dptable[i][j] = arr[i][j] ;

            else if(i==0 && j!=col-1)
                dptable[i][j] = arr[i][j] + dptable[i][j+1] ;

            else if(j==col-1 && i!=0)
                dptable[i][j] = arr[i][j] + dptable[i-1][j] ;

            else if (i%2!=0)
                dptable[i][j] = arr[i][j] + min(dptable[i][j+1],dptable[i-1][j]) ;

            else
            {
                int mn = min(dptable[i][j+1],dptable[i-1][j]);
                dptable[i][j] = arr[i][j] + min(mn,dptable[i-1][j+1]) ;
            }
        }
    }

    return dptable[row-1][0] ;
}
int Calc_Max_Cost(int **arr, int row, int col)
{
    int dptable[row][col] , i, j ;

    for(i=0; i<row; i++)
    {
        for(j=col-1; j>=0; j--)
        {
            if(i==0 && j==col-1)
                dptable[i][j] = arr[i][j] ;

            else if(i==0 && j!=col-1)
                dptable[i][j] = arr[i][j] + dptable[i][j+1] ;

            else if(j==col-1 && i!=0)
                dptable[i][j] = arr[i][j] + dptable[i-1][j] ;

            else if (i%2!=0)
                dptable[i][j] = arr[i][j] + max(dptable[i][j+1],dptable[i-1][j]) ;

            else
            {
                int mn = max(dptable[i][j+1],dptable[i-1][j]);
                dptable[i][j] = arr[i][j] + max(mn,dptable[i-1][j+1]) ;
            }
        }
    }

    return dptable[row-1][0] ;
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
