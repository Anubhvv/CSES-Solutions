#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)
#define mod 1000000007
using namespace std;

vector<int>graph[21];
bool visited[21];
int n;
int counting=0;
int dp[21][1<<21];
int pathNum(int u, int mask)
{
    if(dp[u][mask]==-1)
    {
        if(u==n)
        {
            if(__builtin_popcount(mask)==n)
            {
                dp[n][mask]=1;
                return 1;
            }
            dp[n][mask]=0;
            return 0;
        }
        int paths=0;
        loop(i,0,graph[u].size())
        {
            int v=graph[u][i];
            if(!(mask & 1<<(v-1)))
                paths=( paths+pathNum( v, mask | 1<<(v-1) ) )%mod;
        }
        dp[u][mask]=paths;
    }
    return dp[u][mask];
}
int main()
{
    int m;
    cin>>n>>m;
    loop(i,0,m)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    memset(dp,-1, sizeof dp);
    cout<<pathNum(1,1);
    return 0;
}
