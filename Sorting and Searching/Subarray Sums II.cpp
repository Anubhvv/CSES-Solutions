#include <bits/stdc++.h>
#define loop(i,n) for(long long i=0;i<n;++i)
using namespace std;
int main()
{
    long long n,x,sum=0,ans=0;
    scanf("%lld %lld",&n,&x);
    long long a[n];
    map < long long , long long  > left_sum;
    ++left_sum[0];
    loop(i,n)
    {
        scanf("%lld",a+i);
        sum+=a[i];
        ans+=left_sum[sum-x];
        ++left_sum[sum];
    }
    printf("%lld",ans);
    return 0;
}
