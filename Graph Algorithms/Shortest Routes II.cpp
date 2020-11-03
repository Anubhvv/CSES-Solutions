#include <bits/stdc++.h>
#define loop(i, a, n) for(long long i = a; i < n; ++i)

using namespace std;

int main()
{
    int n, m, q;
    scanf("%d %d %d", & n, & m, & q);
    vector < pair< int , long long > > adj[n+1];
    loop(i,0,m)
    {
        int a,b;
        long long w;
        scanf("%d %d %lld",&a, &b, &w);
        adj[a].push_back(make_pair(b,w));
        adj[b].push_back(make_pair(a,w));
    }
    long long distances[n+1][n+1];
    loop(i,0,n+1)
    loop(j,0,n+1)
        distances[i][j]=1000000000000000; //inf
    loop(i,0,n+1)
        distances[i][i]=0; //self distance = 0
    loop(i,1,n+1)
    loop(j,0,adj[i].size())
    {
        if(distances[i][adj[i][j].first]>adj[i][j].second) //parallel edges pick the shortest length/lowest weight
        {
            distances[i][adj[i][j].first]=adj[i][j].second;
            distances[adj[i][j].first][i]=adj[i][j].second;
        }
    }
    //FLOYD WARSHALL
    loop(k,1,n+1)
    loop(i,1,n+1)
    loop(j,1,n+1)
        if(distances[i][j]>distances[i][k]+distances[k][j])
            distances[i][j]=distances[i][k]+distances[k][j];



    loop(i,0,q)
    {
        int s,e;
        scanf("%d %d",& s, & e);
        if(distances[s][e]==1000000000000000)
            distances[s][e]=-1; // impossible
        printf("%lld\n",distances[s][e]);
    }
    return 0;
}
