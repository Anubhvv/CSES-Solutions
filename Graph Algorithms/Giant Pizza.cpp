#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;

vector<int >graph[200001],rgraph[200001];
bool used[200001];
vector<int>order;
vector<int>scc[200001];
int scc_number[200001];
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
    scc_number[u]=component_count+1;
    loop(i,0,rgraph[u].size())
        if(!used[rgraph[u][i]])
            dfs2(rgraph[u][i]);
}

int main()
{
    int n,m;
    cin>>n>>m;
    loop(i,0,n)
    {
        char c1,c2;
        int a,b;
        cin>>c1>>a>>c2>>b;
        if(c1=='+' and c2=='+')
        {
            graph[a+m].push_back(b);
            rgraph[b].push_back(a+m);
            graph[b+m].push_back(a);
            rgraph[a].push_back(b+m);
        }
        else if(c1=='+' and c2=='-')
        {
            graph[a+m].push_back(b+m);
            rgraph[b+m].push_back(a+m);
            graph[b].push_back(a);
            rgraph[a].push_back(b);
        }
        else if(c1=='-' and c2=='+')
        {
            graph[a].push_back(b);
            rgraph[b].push_back(a);
            graph[b+m].push_back(a+m);
            rgraph[a+m].push_back(b+m);
        }
        else if(c1=='-' and c2=='-')
        {
            graph[a].push_back(b+m);
            rgraph[b+m].push_back(a);
            graph[b].push_back(a+m);
            rgraph[a+m].push_back(b);
        }
    }

    loop(i,1,2*m+1)
    {
        if(!used[i])
            dfs1(i);
    }

    loop(i,0,2*m+1)
        used[i]=false;

    loop(i,0,2*m)
    {
        int u=order[2*m-1-i];
        if(!used[u])
        {
            dfs2(u);
            ++component_count;
        }
    }

   // cout<<"DFS done\n";
/*
    loop(i,0,component_count)
    {
        loop(j,0,scc[i].size())
        {
            int v=scc[i][j];
            if(v>m)
            cout<<m-v<<' ';
            else cout<<v<<' ';
        }
        cout<<endl;
    }
*/
    loop(i,1,m+1)
    {
        if(scc_number[i]==scc_number[i+m])
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }

    char solution[m+1];

    loop(i,0,m+1)
    {
        solution[i]='-';
        used[i]=false;
    }

    int vis_count=0;

    loop(i,0,component_count)
    {
        loop(j,0,scc[component_count-1-i].size())
        {
            int u=scc[component_count-1-i][j];

            if(u>m and !used[u-m])
            {
                solution[u-m]='-';
                used[u-m]=true;
                ++vis_count;
            }
            else if(!used[u])
            {
                solution[u]='+';
                used[u]=true;
                ++vis_count;
            }
            if(vis_count==m)
                break;
        }
        if(vis_count==m)
            break;
    }

    loop(i,1,m+1)
        cout<<solution[i]<<' ';

    return 0;
}
