#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;
vector<int> adj[200001];
int tree[200001];
int dp[200001];
bool include[200001];
int matching;
void dfs(int u,int parent)
{
    loop(i,0,adj[u].size())
    {
        int v=adj[u][i];
        if(v!=parent)
            dfs(v,u);
    }
    if(include[u]==false and include[parent]==false and parent)
    {
        ++matching;
        include[u]=true;
        include[parent]=true;
    }

    return ;
}
int main()
{
    int n;
    cin>>n;
    loop(i,0,n-1)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    cout<<matching;

    return 0;
}
