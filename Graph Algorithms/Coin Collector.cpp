#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;

vector<int >graph[200001],rgraph[200001],scc_dag[200001];
bool used[200001];
vector<int>order;
vector<int>scc[200001];
long long coins[200001];
int scc_num[200001];
int component_count=0;
long long max(long long a,long long b)
{
    if(a>b)
        return a;
    return b;
}
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
    scc_num[u]=component_count+1;
    scc[component_count].push_back(u);
    loop(i,0,rgraph[u].size())
        if(!used[rgraph[u][i]])
            dfs2(rgraph[u][i]);
}
bool visited[100001];
long long coins_dag[100001];
long long dp[100001];
long long dfsDP(int u)
{
  //  cout<<"\t dfs ("<<u<<")\n\n";
    visited[u]=true;
    long long max_coin=0;
    if(!dp[u]){
    loop( j,0,scc_dag[u].size())
    {
        long long x;
        x=dfsDP(scc_dag[u][j]);
        max_coin=max(x,max_coin);

      //  cout<<"\t\tcoin from child of "<<u<<" are "<<x<<endl;
    }
    }
    else return dp[u];
    dp[u]=coins_dag[u]+max_coin;
    return dp[u];
}

int main()
{
    int n,m;
    cin>>n>>m;
    loop(i,1,n+1)
    {
        int c;
        cin>>c;
        coins[i]=c;
    }

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
        //cout<<u<<' ';
        if(!used[u])
        {
            dfs2(u);
            ++component_count;
        }
    }
    loop(i,1,n+1)
    {
        loop(j,0,graph[i].size())
        {
            int v=graph[i][j];
            if(scc_num[i]!=scc_num[v])
                scc_dag[scc_num[i]].push_back(scc_num[v]);
        }
    }
    /*
    cout<<endl;
    loop(i,1,component_count+1)
    {
        cout<<i<<"  -> ";
        loop(j,0,scc_dag[i].size())
        {
            cout<<scc_dag[i][j]<<' ';
        }
        cout<<endl;
    }
*/
    long long coins_total=0;
    loop(i,0,component_count)
    {
        coins_total=0;
      //  cout<<"comp_num="<<i+1<<endl;
        loop(j,0,scc[i].size())
        {
            int v=scc[i][j];
           // cout<<v<<' ';
            coins_total+=coins[v];
        }
        coins_dag[i+1]=coins_total;
       // cout<<"coins="<<coins_dag[i+1]<<endl;
       // cout<<endl;
    }
    //cout<<"The answer bilkul final is "<<
    long long max_ans=0;
    loop(i,1,component_count+1)
    {
        if(!visited[i])
            max_ans=max(max_ans,dfsDP(i));
    }
    cout<<max_ans<<endl;
    return 0;
}
