#include <bits/stdc++.h>
using namespace std;
int p[10000000],n,x;
int main()
{
    scanf("%d %d",&n,&x);
    for(int i=0;i<n;i++)
        scanf("%d",&p[i]);
    sort(p,p+n);
    int ans=0;
    for(int i=0, j = n-1 ;i <n ; i++ )
    {
        while(i<j  and  p[i] + p[j] > x )
        --j;
        if( j > i )
            ++ans;
        if( i > j )
            break;
            --j;
    }
    printf("%d",n-ans);
    return 0;
}
