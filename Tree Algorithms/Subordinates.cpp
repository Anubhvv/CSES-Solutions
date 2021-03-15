#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;
vector<int> adj[200001];
int tree[200001];
int subordinates[200001];
void dfs(int u,int parent)
{
    subordinates[u]=1;
    //cout<<"dfs "<<u<<endl;
    loop(i,0,adj[u].size())
    {
        int v=adj[u][i];
       // cout<<"v="<<v<<endl;

        if(v!=parent)
        {
           dfs(v,u);
           //cout<<"for node "<<u<<" :";
           subordinates[u]+= subordinates[v];
          // cout<<" +sub["<<v<<"]="<<"+"<<subordinates[v]<<endl;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    loop(i,2,n+1)
    {
        cin>>tree[i];
        adj[tree[i]].push_back(i);
        adj[i].push_back(tree[i]);
    }
    dfs(1,0);
    loop(i,1,n+1)
        if(subordinates[i])
        cout<<subordinates[i]-1<<' ';
        else cout<<0<<' ';

    return 0;
}
