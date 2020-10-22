#include <bits/stdc++.h>
#define loop(i,a,n) for(long long i=a;i<n;++i)
int dp[1000001]={0};
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    int coins[n];
    loop(i,0,n)
        cin>>coins[i];
    dp[0]=1;
    loop(j,1,x+1)
        loop(i,0,n)
         {
             if(j>=coins[i])
                dp[j]= ( dp[j]+dp[j-coins[i]] )% 1000000007;
         }
    printf("%d",dp[x]);
    
