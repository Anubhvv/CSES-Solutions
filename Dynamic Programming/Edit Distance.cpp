#include <bits/stdc++.h>
#define loop(i,a,n) for(long long i=a;i<n;++i)
int dp[5001][5001];
char t[5001],o[5001];
int n,m;
using namespace std;
int rec(int io,int it)
{
    if(io==-1)
        return it+1;
    if (it==-1)
        return io+1;
    if(dp[io][it]==-1)
    {
        if(o[io]==t[it])
            dp[io][it]=rec(io-1,it-1);
        else dp[io][it]=min(min(1+rec(io-1,it),1+rec(io-1,it-1)),1+rec(io,it-1));
    }
    return dp[io][it];
}
int main()
{
    memset(dp,-1,sizeof dp);
    cin>>o;
    cin>>t;
    n=strlen(o);
    m=strlen(t);
    printf("%d",   rec(n-1,m-1)   );
    return 0;
}
