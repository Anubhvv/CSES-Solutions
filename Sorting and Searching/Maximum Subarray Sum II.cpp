#include <bits/stdc++.h>
#define loop(i,n) for(long long i=0;i<n;++i)
using namespace std;
int main()
{
    long long n,a,b,ans=0,temp;

    scanf("%lld %lld %lld",&n,&a,&b);
    multiset < long long > upto_b;
    vector < long long > cumulative;
    upto_b.insert(0);
    loop(i,n)
    {
        scanf("%lld",&temp);
        cumulative.push_back(temp);
    }
    bool zero=1;
    for(long long i =1 ; i<n ;++i)
        cumulative[i]+=cumulative[i-1];
    ans=-1000000000;
    ans=cumulative[a-1];
    for(long long i=a;i<n;++i)
    {
        if(i==b)
        {   if(zero)
            {
                upto_b.erase(upto_b.find(0));
                zero=false;
            }
        }
        if(i>b)
            upto_b.erase(upto_b.find(cumulative[i-b-1]));
        upto_b.insert(cumulative[i-a]);
        if( ans<cumulative[i]-*(upto_b.begin()))
            ans=cumulative[i]-*(upto_b.begin());
    }
    printf("%lld",ans);
    return 0;
}
