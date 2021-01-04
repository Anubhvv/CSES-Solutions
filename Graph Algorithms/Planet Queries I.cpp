#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;

int adj[200001];
int ancestor[200001][33];   //33>log2(2x10^9)

int main()
{
    int n, q;
    scanf("%d %d", & n, & q);
    loop(i,1,n+1)
    {
        scanf("%d",&adj[i]);
    }

    loop(i,1,n+1)
        ancestor[i][0]=adj[i];
    loop(i,1,33)
    {
        loop(j,1,n+1)
        {
            ancestor[j][i]=ancestor[ ancestor[j][i-1] ][i-1];
        }
    }

    while(q--)
    {
        int k;
        int start;
        cin>>start>>k;

        long long jump;

        int ans=start;

        while(k)
        {
            jump=log2(k);
            ans=ancestor[ans][jump];
            k-=(1<<jump);
        }

        cout<<ans<<endl;
    }
    return 0;
}
