#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;
int n,m;
vector<int> adj[100001];
bool visited[100001];
int indeg[100001];
int costs[100001],parent[100001];
stack<int> indeg0;
queue < int > topologOrder;
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
        int course=indeg0.top();
        topologOrder.push(course);
        //cout<<" course : "<<course<<endl;
        //cout<<course<<" indeg:"<<indeg[course]<<endl;
        indeg0.pop();
        if(indeg[course])
            return false;
        loop(i,0,adj[course].size())
        {
            if(!(--indeg[adj[course][i]]))
                indeg0.push(adj[course][i]);
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
    /*
    cout<<"indeg array:";
    loop(i,1,n+1)
        cout<<indeg[i]<<' ';
    cout<<endl;
    */
    if(!topSort())
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    int ninf=-1000000000;
    loop(i,1,n+1)
    {
        costs[i]=ninf;
        parent[i]=-2;
    }
    costs[1]=1;

    while(!topologOrder.empty())
    {
        int u=topologOrder.front();

        topologOrder.pop();
        loop(i,0,adj[u].size())
        {
            int v=adj[u][i];

            if(costs[v]<costs[u]+1 and costs[u]!=ninf)
            {
                costs[v]=costs[u]+1;
                parent[v]=u;
            }
        }
    }

    if(costs[n]==ninf)
   {
       cout<<"IMPOSSIBLE";
       return 0;
   }
   //Retracing the path
    vector <int > path;
    parent[1]=-1;

    int city=n;
    while(city!=-1) //parent ==-1 means starting node
    {
        path.push_back(city);
        city=parent[city];
    }
    cout<<path.size()<<endl;
    loop(i,0,path.size())
        cout<<path[path.size()-i-1]<<' ';
    return 0;
}
