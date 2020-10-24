#include <bits/stdc++.h>
#define loop(i,a,n) for(long long i=a;i<n;++i)
int cuts[501][501],a,b;
using namespace std;
int rec(int i, int j)
{
    if(!cuts[i][j])
    {
        if(i==j)
            cuts[i][j]=0;
        else if(i==1)
            cuts[i][j]=j-1;
        else if(j==1)
            cuts[i][j]= i-1;
        else{
            int ans=1000000000;
            for(int l=1;l<i;++l)
                ans=min(ans,rec(l,j)+rec(i-l,j));
            for(int l=1;l<j;++l)
                ans=min(ans,rec(i,l)+rec(i,j-l));
            ++ans;
            cuts[i][j]=ans;
        }
    }
    return cuts[i][j];

}
int main()
{
    scanf("%d %d",&a,&b);
    printf("%d",  rec(a,b) );
    return 0;
}
