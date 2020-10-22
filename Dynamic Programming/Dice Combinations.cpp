#include <bits/stdc++.h>
#define loop(i,a,n) for(long long i=a;i<n;++i)
int dp[1000001]={0};
using namespace std;
int main()
{
    int n,dice[]={1,2,3,4,5,6};
    cin>>n;
    dp[0]=1;
    loop(x,1,n+1)
    {
        loop(i,0,6)
        if(x>=dice[i])
        dp[x]= ( dp[x]+dp[x-dice[i]] )% 1000000007;
    }
    printf("%d",dp[n]);
    return 0;
}
