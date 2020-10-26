#include <bits/stdc++.h>
#define loop(i, a, n) for (long long i = a; i < n; ++i)
int n,m;
long long x[200001],dp[200001][101];
using namespace std;
int main()
{
    scanf("%d %d", & n, & m);
    scanf("%lld",x);
    if(x[0])
    {
        dp[0][x[0]]=1;
    }
    else
    {
        loop(i,1,m+1)
        dp[0][i]=1;
    }
    loop(i,1,n)
    {
        scanf("%lld",x+i);
        if(! x[i])
        {
            loop(j,1,m+1)
            {
                long long k=j-1;
                if(k>=1 and k<=m)
                dp[i][j]=(dp[i][j]+dp[i-1][k])%1000000007;
                ++k;
                if(k>=1 and k<=m)
                dp[i][j]=(dp[i][j]+dp[i-1][k])%1000000007;
                ++k;
                if(k>=1 and k<= m)
                dp[i][j]=(dp[i][j]+dp[i-1][k])%1000000007;
            }
        }
        else{
                long long j=x[i];
            int k=j-1;
                if(k>=1 and k<=m)
                dp[i][j]=(dp[i][j]+dp[i-1][k])%1000000007;
                ++k;
                if(k>=1 and k<=m)
                dp[i][j]=(dp[i][j]+dp[i-1][k])%1000000007;
                ++k;
                if(k>=1 and k<= m)
                dp[i][j]=(dp[i][j]+dp[i-1][k])%1000000007;
        }
    }
    long long ans=0;
    loop(i,1,m+1)
        ans=(ans+dp[n-1][i])%1000000007;
    printf("%lld", ans);
    return 0;
}
