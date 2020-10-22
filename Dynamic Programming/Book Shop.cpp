#include <bits/stdc++.h>
#define loop(i,a,n) for(long long i=a;i<n;++i)
int maxPages[1001][100001];
using namespace std;
int main()
{
    int n,x;
    scanf("%d %d",&n,&x);
    int price[n+1],pages[n+1];
    loop(i,1,n+1)
        scanf("%d",price+i);
    loop(i,1,n+1)
        scanf("%d",pages+i);
    loop(i,1,n+1)
    {
        loop(j,0,x+1)
        {
            maxPages[i][j]=maxPages[i-1][j];
            if(j>=price[i])
               maxPages[i][j] = max( maxPages[ i ][ j ]  , maxPages[ i - 1 ][ j - price[i] ] + pages[ i ] );
        }
    }
    printf("%d",maxPages[n][x]);
    return 0;
}
