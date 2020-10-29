#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;
vector<int> cities[200001];
bool visited[100001];
int last_visited=1;
void dfs(int s)
{
    if(visited[s])
        return;
    visited[s]=true;
    last_visited=s;
    loop(i,0,cities[s].size())
        dfs(cities[s][i]);
}

int main()
{
    int n,m; //cities, roads
    scanf("%d %d", & n, & m);
    int a,b;
    loop(i,0,m)
    {
        scanf("%d %d",&a,&b);
        cities[a].push_back(b);
        cities[b].push_back(a);
    }
    int roads=0;
    dfs(1);
    vector < pair < int , int > > construct;
    loop(i,2,n+1)
    {
        if(!visited[i])
        {
            cities[i].push_back(last_visited);
            cities[last_visited].push_back(i);
            ++roads;
            construct.push_back(make_pair(i,last_visited));
            dfs(i);
        }
    }
    printf("%d\n",roads);
    loop(i,0,construct.size())
        printf( "%d %d\n", construct[i].first , construct[i].second );
    return 0;
}
