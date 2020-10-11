#include <bits/stdc++.h>
#define loop(i,n) for(long long i=0;i<n;++i)
using namespace std;
int main()
{
    long long n,sum=0,ans=0,min_sum=0;
    scanf("%lld",&n);
    long long a[n];
    map < long long , long long  > left_rem;
    ++left_rem[0];
    long long s_ind;
    loop(i,n)
    {
        scanf("%lld",a+i);
        sum=((sum+a[i])%n+n)%n;
        ans+=left_rem[sum];
        ++left_rem[sum];
    }
    printf("%lld",ans);
    return 0;
}
