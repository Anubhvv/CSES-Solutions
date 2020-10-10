#include <bits/stdc++.h>
#define loop(i,n) for(long long i=0;i<n;++i)
using namespace std;
int main()
{
    long long n,x;
    scanf("%lld %lld",&n,&x);
    long long a[n],cumulative[n];
    loop(i,n)
        scanf("%lld",a+i);

    cumulative[0]=a[0];
    for(long long i=1;i<n;i++)
        cumulative[i] = cumulative[i-1] + a[i];
    long long ans=0;
    for(long long i=n-1;i>-1 and cumulative[i]>=x;--i)
        if(binary_search(cumulative,cumulative+i+1,cumulative[i]-x) or cumulative[i]==x)
            ++ans;
    printf("%lld",ans);
    return 0;
}
