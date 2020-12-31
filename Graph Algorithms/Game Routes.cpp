#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;
int n,m;
vector<int> adj[100001];
bool visited[100001];
int indeg[100001];
stack<int> indeg0;
queue < int > topologOrder;
int ways[100001];
void fill_inDeg()
{
    loop(i,1,n+1)
    {
        loop(j,0,adj[i].size())
        {
            ++indeg[adj[i][j]];
        }
    }
}
bool topSort()
{
    loop(i,1,n+1)
    {
        if(!indeg[i])
        {
            indeg0.push(i);
        }
    }
    if(indeg0.empty())
        return false;

    while(!indeg0.empty())
    {
        int level=indeg0.top();
        topologOrder.push(level);
        //cout<<"course :"<< course<<endl;
        //cout<<course<<" indeg:"<<indeg[course]<<endl;
        indeg0.pop();
        if(indeg[level])
            return false;
        loop(i,0,adj[level].size())
        {
            if(!(--indeg[adj[level][i]]))
                indeg0.push(adj[level][i]);
        }
    }
    if(topologOrder.size()<n)
        return false;
    return true;
}

int main()
{
    scanf("%d %d", & n, & m);
    int a,b;
    loop(i,0,m)
    {
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
    }

    fill_inDeg();

    topSort();

    //TOPOLOGICAL SORTING DONE


    if(adj[1].size())
        ways[1]=1;
    while(!topologOrder.empty())
    {
        int u=topologOrder.front();
        topologOrder.pop();
       // cout<<" u : "<<u<<endl;
        loop(i,0,adj[u].size())
        {
            int v=adj[u][i];
            //cout<<"\t v : "<<v<<endl;
            ways[v]=(ways[v]+ways[u])%1000000007;
            //cout<<"\t ways "<<v<<" = "<<ways[v]<<endl;

        }

    }
    cout<<ways[n];
    return 0;
}
