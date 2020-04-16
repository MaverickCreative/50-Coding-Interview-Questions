//The code assumes that 0 is not a valid input for any cell of the matrix and all
//values are >=1

#include <bits/stdc++.h>

using namespace std;

int a[3][3];       //The code can be customized to rows and columns of any length
int maxP[3][3];
int minP[3][3];


int product(int a[][3], int r , int c)
{
    int p = 1;
    for(int i=0;i<c;i++)
    {
        maxP[0][i] = a[0][i]*p;
        minP[0][i] = a[0][i]*p;
        p = maxP[0][i];
    }
    p = 1;
    for(int i=0;i<r;i++)
    {
        maxP[i][0] = a[i][0]*p;
        minP[i][0] = a[i][0]*p;
        p = maxP[i][0];
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(maxP[i][j]==0 && minP[i][j]==0)
            {
                int z = a[i][j]*maxP[i-1][j];
                int b = a[i][j]*maxP[i][j-1];
                int c = a[i][j]*minP[i-1][j];
                int d = a[i][j]*minP[i][j-1];
                int maxVal = max(max(z,b),max(c,d));
                int minVal = min(min(z,b),min(c,d));
                maxP[i][j] = maxVal;
                minP[i][j] = minVal;
            }
        }
    }
    return max(maxP[r-1][c-1],minP[r-1][c-1]);
}

int main(){
    int r,c;
    cin>>r>>c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            maxP[i][j] == 0;
            minP[i][j] == 0;
        }
    }
 
    int answer = product(a, 3 , 3);
    cout<<answer<<endl;
}
