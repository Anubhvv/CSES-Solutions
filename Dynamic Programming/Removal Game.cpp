#include <bits/stdc++.h>
#define loop(i,a,n) for(long long i=a;i<n;++i)
int cards[5001];
long long max_score[5001][5001];
using namespace std;
long long rec(int left, int right)
{
    if(max_score[left][right]==-1)
        if(left>=right)
            max_score[left][right]=0;
       else max_score[left][right]=max( cards[left] + min( rec( left+2 , right ) , rec( left+1 , right-1 ) )
                                       , cards[right]+min( rec( left , right-2 ) , rec( left+1 , right-1 ) ) );
    return max_score[left][right];
}
int main()
{
    int n;
    scanf("%d",&n);
    loop(i,0,n)
        scanf("%d",cards+i);
    memset(max_score,-1,sizeof max_score);
    printf("%lld ",rec(0,n-1));
    return 0;
}
