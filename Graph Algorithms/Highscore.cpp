#include <bits/stdc++.h>
#define loop(i, a, n) for(long long i = a; i < n; ++i)
using namespace std;
long long min(long long a, long long b)
{
    if(a<b)
        return a;
    return b;
}
long long max(long long a, long long b)
{
    if(a>b)
        return a;
    return b;
}
int main()
{
    int n, m;
    long long inf=1000000000000000;
    scanf("%d %d", & n, & m);
    priority_queue< pair< long long, int > > maxheap;
    vector < pair< int , long long > > adj[n+1];
    loop(i,0,m)
    {
        int a,b;
        long long w;
        scanf("%d %d %lld",&a, &b, &w);
        adj[a].push_back(make_pair(b,-w));
    }
    long long distances[n+1];
    loop(i,0,n+1)
        distances[i]=inf;
    distances[1]=0;
    loop(k,0,n-1)
    {
        loop(i,1,n+1)
        {
            loop(j,0,adj[i].size())
            {
                if(distances[i]!=inf)
                distances[adj[i][j].first]=min(distances[adj[i][j].first],distances[i]+adj[i][j].second);
            }
        }
    }
    loop(k,0,n-1)
    {
        loop(i,1,n+1)
        {
            loop(j,0,adj[i].size())
            {
                if(distances[adj[i][j].first]!=inf)
                {
                    if(distances[adj[i][j].first]>distances[i]+adj[i][j].second)
                        distances[adj[i][j].first]=-inf;
                }
            }
        }
    }
    if(distances[n]==-inf)
        distances[n]=1;
    cout<<-distances[n];
    return 0;
}
