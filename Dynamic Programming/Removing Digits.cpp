#include <bits/stdc++.h>
#define loop(i,a,n) for(long long i=a;i<n;++i)
using namespace std;
int dp[1000000];
int rec(int n)
{
    if(n==0) return 0;
    if(n<0) return 1000000000;
    if(dp[n])
        return dp[n];
    int num=n;
    int ans=1000000000;
    while(num)
    {
        if(num%10)
            ans=min( ans , 1+rec(n-num%10) ) ;
        num/=10;
    }
    dp[n]=ans;
    return ans;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",rec(n));
    return 0;
}
