#include <bits/stdc++.h>
#define loop(i, a, n) for( int i = a; i < n; ++i )
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
    loop(i,1,n+1)
        distances[i]=0;
    //distances[1]=0;
    int parent[n+1];
    bool negCyc=false;
    int start=-1;
   // int relaxant[n+1];
    negCyc=false;
    loop(k,0,n)
    {
        negCyc=false;
        loop(i,1,n+1)
        {
            loop( j, 0, adj[i].size() )
            {
           // if(distances[i]!=inf)
            //{
                if(distances[adj[i][j].first]>distances[i]-adj[i][j].second)
                {
                    distances[adj[i][j].first]=distances[i]-adj[i][j].second;
                    parent[adj[i][j].first]=i;
                    start=adj[i][j].first;
                    negCyc=true;
                }
            //}
            }
        }
    }
    if(negCyc)
    {
        cout<<"YES\n";
        vector < int > neg_path;
        loop(i,0,n)
           start=parent[start];
        int node=start;

        while(true)
        {
            neg_path.push_back(node);
            node=parent[node];
            if(node==start)// and neg_path.size()>=1)
                break;
        }
        neg_path.push_back(node);
        for(int i=neg_path.size()-1; i >=0 ; --i)
            cout<<neg_path[i]<<' ';
    }

    else cout<<"NO";
    return 0;
}
