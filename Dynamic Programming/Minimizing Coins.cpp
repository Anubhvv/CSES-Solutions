#include <bits/stdc++.h>
#define loop(i,n) for(long long i=0;i<n;++i)

using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    int c[n];
    loop(i,n)
        cin>>c[i];
    int dp[x];
    dp[0]=0;
    for(int i=1;i<=x;++i)
    {
        dp[i]=2000000000;
        loop(j,n)
        {
            if(i - c[j] >= 0)
                dp[i]=min(dp[i],dp[i-c[j]]+1);
        }
    }
    if(dp[x]==2000000000)
        dp[x]=-1;
    cout<<dp[x];
    return 0;
}
