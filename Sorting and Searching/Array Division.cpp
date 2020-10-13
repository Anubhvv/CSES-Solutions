#include <bits/stdc++.h>
#define loop(i,n) for(long long i=0;i<n;++i)
using namespace std;
int main()
{
    long long n,k,max_ele=0,left,right,max_sum,ans=0,maximum_sum=0,tot=0, mid;
    scanf("%lld %lld",&n,&k);
    long long x[n];
    loop(i,n)
    {
        scanf("%lld",x+i);
        if(x[i]>max_ele)
            max_ele=x[i];
        tot+=x[i];
    }
    left=max_ele;
    right =  tot;
    while(left<right)
    {
        mid = (left+right)/2;
        int c=1;
        max_sum=0;
        loop(i,n)
        {
            if(max_sum+x[i]>mid)
            {
                max_sum=0;
                ++c;
            }
            max_sum+=x[i];
        }
        if(c>k)
            left=mid+1;
        else if (c<=k)
            right=mid;
    }

    printf("%lld",left);
    return 0;
}
