#include <bits/stdc++.h>
#define loop(i,n) for(long long i=0;i<n;++i)
using namespace std;
int main()
{
    long long n;
    scanf("%lld",&n);
    long long a[n],sum[n],tot,minCost=100000000000000,temp;
    loop(i,n)
        scanf("%lld",a+i);
    sort(a,a+n);
    loop(i,n)
    {
        if(i>0)
        sum[i]=a[i]+sum[i-1];
        else sum[0]=a[0];
    }
    tot=sum[n-1];
    for(int i=1;i<n;i++)
    {
        temp=tot-sum[i]-(n-i-1)*a[i]+(i)*a[i]-sum[i-1];
        if(minCost>temp)
            minCost=temp; //0 1 2 3 4
    }
    printf("%lld",minCost);
    return 0;
}
