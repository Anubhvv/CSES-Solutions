#include <bits/stdc++.h>
#define loop(i,a,n) for(long long i=a;i<n;++i)
using namespace std;
int paths[1001][1001];
int main()
{
    int n;
    scanf("%d",&n);
    char grid[n][n+1];
    loop(i,0,n)
            scanf("%s",grid[i]);
    if(grid[0][0]=='.')
        paths[0][0]=1;
 
    loop(i,0,n)
    loop(j,0,n)
    {
        if(grid[i][j]=='.'){
            if(i>=1)
                paths[i][j]=paths[i-1][j];
            if(j>=1)
                paths[i][j]=(paths[i][j]+paths[i][j-1])%1000000007;
        }
    }
    printf("%d",paths[n-1][n-1]);
    return 0;
}
