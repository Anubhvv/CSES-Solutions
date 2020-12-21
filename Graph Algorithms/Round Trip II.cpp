#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;

vector<int> cities[100001];
bool visited[100001];
bool rsflag[100001];
int start=-1;
stack <int> recStack;
bool dfs(int node)
{
    visited[node]=true;
    rsflag[node]=true;
    recStack.push(node);
    loop( i, 0, cities[node].size() )
    {
        if(!visited[cities[node][i]])
        {
            if(dfs(cities[node][i]))
                return true;
        }
        else if(rsflag[cities[node][i]])
        {
            recStack.push(cities[node][i]);
            start=cities[node][i];
            return true;
        }
    }
    recStack.pop();
    rsflag[node]=false;
    return false;
}
int main()
{
    int n, m;
    scanf("%d %d", & n, & m);
    int a,b;
    loop(i,0,m)
    {
        scanf("%d %d",&a,&b);
        cities[a].push_back(b);
    }
    bool cycle_found=false;
    loop(i,1,n+1)
    {

        if(!visited[i])
            cycle_found|=dfs(i);
        if(cycle_found)
            break;
    }
    if(!cycle_found)
    {
      cout<<"IMPOSSIBLE";
      return 0;
    }
    vector<int>path;
    path.push_back(start);
    recStack.pop();
    while(recStack.top()!=start)
    {
        path.push_back(recStack.top());
        recStack.pop();
    }
    path.push_back(start);
    cout<<path.size()<<endl;
    loop(i,0, path.size() )
        cout<<path[path.size()-i-1]<<' ';
    return 0;
}
