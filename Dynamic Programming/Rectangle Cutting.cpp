#include <bits/stdc++.h>
#define loop(i,a,n) for(long long i=a;i<n;++i)
int dp[5001][5001];
using namespace std;
int main()
{
    char t[5001],o[5001];
    int n,m;
    cin>>o;
    cin>>t;
    n=strlen(o);
    m=strlen(t);
    for(int j=0;j<=m;++j)
        dp[0][j]=j;
    for(int i=1;i<=n;++i)
    {
        dp[i][0]=i;
        for(int j=1;j<=m;++j)
        if(o[i-1]==t[j-1])
            dp[i][j]=dp[i-1][j-1];
        else dp[i][j]= min ( min( 1+dp[i-1][j],1+dp[i-1][j-1]),1+dp[i][j-1]);
    }
    printf("%d",  dp[n][m]  );
    return 0;
}
