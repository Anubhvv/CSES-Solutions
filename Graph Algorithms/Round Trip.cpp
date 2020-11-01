#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;

vector<int> cities[100001];
bool visited[100001];
int parents_retrieval[100001];//useful in path retrieval
bool cycle_found=false;
int start,ending;

void dfs(int child, int parent)
{
    visited[child]=true;
    parents_retrieval[child]=parent;
    loop(i,0,cities[child].size())
    {
        if(visited[cities[child][i]])
        {
            if(cities[child][i]!=parent)  // unvisited neighbor who is not a parent = cycle found
            {
                ending=cities[child][i];
                start=child;
                cycle_found=true;
            }
        }
        else dfs( cities[child][i] , child );
    }
    return;
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
        cities[b].push_back(a);
    }
    loop(i,1,n+1)
    {

        if(!visited[i])
            dfs(i,-1);
        if(cycle_found)
            break;
    }
    if(!cycle_found)
    {
      cout<<"IMPOSSIBLE";
      return 0;
    }
    /////////Retrieving Path
    vector< int > path;
    int city=ending;
    while(city!=start)
    {
        path.push_back(city);
        city=parents_retrieval[city];
    }

    path.push_back(start);
    path.push_back(ending);
    ////Outputting
    cout<<path.size()<<endl;
    loop(i,0,path.size())
        printf("%d ",path[i]);

    return 0;
}
