#include <bits/stdc++.h>
#define loop(i,a,n) for(long long i=a;i<n;++i)
using namespace std;
int dp[1000000];
int main()
{
    int n;
    scanf("%d",&n);
    loop(i,0,n)
        dp[i]=1000000000;
    dp[0]=0;
    for(int i=1;i<=n; ++i)
    {
        int num=i;
        int ans=1000000000;
        while(num)
        {
            if(num%10)
                if(i>=num%10)
                ans=min( ans , 1+dp[(i-num%10)] ) ;
            num/=10;
        }
        dp[i]=ans;
    }
    printf("%d",dp[n]);
    return 0;
}
