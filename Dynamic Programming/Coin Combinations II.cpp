#include <bits/stdc++.h>
#define loop(i,a,n) for(long long i=a;i<n;++i)
int dp[1000001]={0};
using namespace std;
int main()
{
    int n,x;
    scanf("%d %d",&n,&x);
    int coins[n];
    loop(i,0,n)
        cin>>coins[i];
    dp[0]=1;
    loop(i,0,n)
        loop(j,1,x+1)
            if(coins[i]<=j)
                dp[j]=(dp[j]+dp[j-coins[i]])%1000000007;
    printf("%d",*(dp+x));
}
