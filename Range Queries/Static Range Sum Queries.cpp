#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)
#define mod 1000000007
using namespace std;

int main()
{
    int n,q,a,b;
    cin>>n>>q;
    long long arr[n],cummul[n];
    loop(i,0,n)
        cin>>arr[i];
    cummul[0]=arr[0];
    loop(i,1,n)
        cummul[i]=cummul[i-1]+arr[i];
    while(q--)
    {
        cin>>a>>b;
        --a;--b;
        if(a>=1)
        cout<<cummul[b]-cummul[a-1]<<'\n';
        else cout<<cummul[b]<<'\n';
    }
    return 0;
}
