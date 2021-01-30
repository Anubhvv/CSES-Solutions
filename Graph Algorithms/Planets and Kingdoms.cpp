#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;

vector<int >graph[200001],rgraph[200001];
bool used[200001];
vector<int>order;
vector<int>scc[200001];
int component_count=0;

void dfs1(int u)
{
    used[u]=true;
    loop(i,0,graph[u].size())
        if(!used[graph[u][i]])
        dfs1(graph[u][i]);
    order.push_back(u);
}

void dfs2(int u)
{
    used[u]=true;
    scc[component_count].push_back(u);
    loop(i,0,rgraph[u].size())
        if(!used[rgraph[u][i]])
            dfs2(rgraph[u][i]);
}

int main()
{
    int n,m;
    cin>>n>>m;
    loop(i,0,m)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        rgraph[b].push_back(a);
    }

    loop(i,1,n+1)
    {
        if(!used[i])
            dfs1(i);
    }
    loop(i,0,n+1)
        used[i]=false;

    loop(i,0,n)
    {
        int u=order[n-1-i];
        if(!used[u])
        {
            dfs2(u);
            ++component_count;
        }
    }

    //outputting answer in proper format
    int ans[n+1];

    loop(i,0,component_count)
    {
        loop(j,0,scc[i].size())
        {
            ans[scc[i][j]]=i+1;
        }
    }
    cout<<component_count<<endl;
    loop(i,1,n+1)
    cout<<ans[i]<< ' ';
    return 0;
}
