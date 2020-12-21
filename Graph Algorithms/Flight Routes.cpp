#include <bits/stdc++.h>
#define loop(i, a, n) for(long long i = a; i < n; ++i)
int n,k;
using namespace std;
void display(vector< vector< long long > > costs)
{
    cout<<"costs table\n";
    loop(i,1,n+1)
    {
        loop(j,0,k)
            cout<<costs[i][j]<<' ';
        cout<<endl;
    }

}
int main()
{
    int m;
    scanf("%d %d %d", & n, & m, & k);
    priority_queue < pair < long long, int > > maxheap;
    vector < pair < int , long long > > adj[n+1];
    loop(i,0,m)
    {
        int a,b;
        long long c;
        scanf("%d %d %lld",& a , & b , & c );
        adj[a].push_back(make_pair(b,c));
    }
    vector< vector < long long> > costs;

    costs.resize(n+1);
    loop(i,1,n+1)
    loop(j,0,k)
        costs[i].push_back(1000000000000000);

    costs[1][0]=0;
    //DJIKSTRA's ALGO MODIFIED
    maxheap.push(make_pair(0,1));
    while(!maxheap.empty())
    {
        int u = maxheap.top().second;
        long long d=(-maxheap.top().first);
        maxheap.pop();
        if(costs[u][k-1]>=d)
        {

            loop( i , 0 , adj[u].size() )
            {
                int v = adj[u][i].first;
                long long c=adj[u][i].second;

                if( costs[v][k-1] > d+ c  )
                {
                    costs[ v ][k-1] = d + c;
                    maxheap.push(make_pair( -costs[v][k-1] , v ));
                    sort(costs[v].begin(),costs[v].end());
                //    display(costs);
                }
            }
        }
    }

    //cout<<"______________________________________________\n";
    loop(i,0,k)
        cout<<costs[n][i]<<' ';
    return 0;
}
