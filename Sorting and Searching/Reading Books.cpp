#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;++i)
using namespace std;
int main()
{
    int n,btime;
    long long sum=0,max_time=0;
    scanf("%d",&n);
    loop(i,n){
        scanf("%d",&btime);
        sum+=btime;
        if(btime>max_time)
            max_time=btime;
    }
    if( max_time<<1 >sum)
    printf("%lld",max_time<<1);
    else printf("%lld",sum);
    return 0;
}
