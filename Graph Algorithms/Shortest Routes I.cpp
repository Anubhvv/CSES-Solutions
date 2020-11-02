#include <bits/stdc++.h>
#define loop(i, a, n) for(long long i = a; i < n; ++i)

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", & n, & m);
    priority_queue< pair< long long, int > > maxheap;
    vector < pair< int , long long > > adj[n+1];
    loop(i,0,m)
    {
        int a,b;
        long long w;
        scanf("%d %d %lld",&a, &b, &w);
        adj[a].push_back(make_pair(b,w));
    }
    long long distances[n+1];
    bool processed[n+1];
    loop(i,0,n+1)
        distances[i]=1000000000000000; //inf
    distances[1]=0;
    memset(processed,0,sizeof processed);
    //DJIKSTRA's ALGO
    maxheap.push(make_pair(0,1));
    while(!maxheap.empty())
    {
        int cur_city = maxheap.top().second;
        maxheap.pop();
        if( ! processed[  cur_city ] )
        {
            processed[cur_city]=true;

            loop( i , 0 , adj[cur_city].size() )
            {
                int city = adj[cur_city][i].first ;
                long long dist=adj[cur_city][i].second;

                if( distances[ city ] > distances[cur_city] + dist  )
                    distances[ city ] = distances[ cur_city ] + dist ;
                maxheap.push(make_pair(-distances[city], city ));
            }
        }
    }
    loop(i,1,n+1)
        cout<<distances[i]<<' ';
    return 0;
}
