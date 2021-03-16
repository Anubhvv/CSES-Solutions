#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;
vector<int> adj[200001];
int tree[200001];
int dp[200001];
int leaf[200001];
bool include[200001];
int matching;
int dfs(int u,int parent)
{
   // cout<<"dfs " <<u<<endl;
    if(adj[u].size()==1 and parent)
    {
        leaf[u]=u;
        return 0;
    }
    int max_dis=0;
    loop(i,0,adj[u].size())
    {
        int v=adj[u][i];
        if(v!=parent)
        {
            int temp=1+dfs(v,u);
            if(max_dis<=temp)
            {
                max_dis=temp;
                leaf[u]=leaf[v];
            }
        }
    }
    //cout<<"leaf["<<u<<"]="<<leaf[u]<<endl;
    return max_dis;
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
    cout<<dfs(leaf[1],0);
    return 0;
}
