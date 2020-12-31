#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;
int n,m;
vector< pair<int,long long> > adj[100001]; //destination, price

bool processed[100001];

int ways[100001];
long long price[100001];
int minFlights[100001], maxFlights[100001];


int main()
{
    scanf("%d %d", & n, & m);
    int a,b;
    long long c;
    loop(i,0,m)
    {
        scanf("%d %d %lld",&a,&b,&c);
        adj[a].push_back(make_pair(b,c)); //a---$c--->b
    }


    //TOPOLOGICAL SORTING DONE
    long long inf=100000000000000000;
    loop(i,0,n+1)
    {
        price[i]=inf;
        ways[i]=0;
        minFlights[i]=100000000;
    }

    if(adj[1].size())
    {
        ways[1]=1;
        price[1]=0;
        minFlights[1]=0;
        maxFlights[1]=0;
    }

    priority_queue< pair< long long, int > > maxheap;

    memset(processed,0,sizeof processed);
    //DJIKSTRA's ALGO
    maxheap.push(make_pair(0,1));


    while(!maxheap.empty())
    {
          //cout<<"wtf\n";
        int u=maxheap.top().second;
        maxheap.pop();
        //cout<<" u : "<<u<<endl;
        if(!processed[u])
        {

            processed[u]=true;
            loop(i,0,adj[u].size())
            {
                int v=adj[u][i].first;
                long long c=adj[u][i].second;
                //cout<<"\t v : "<<v<<endl;
                if(price[v]>price[u]+c)
                {
                   // cout<<"hello mf\n";
                    price[v]=(price[u]+c);
                   // cout<<"price["<<v<<"]="<<price[v]<<endl;
                    ways[v]=ways[u];
                    minFlights[v]=minFlights[u]+1;
                    maxFlights[v]=1+maxFlights[u];
                    maxheap.push(make_pair(-price[v], v ));
                }
                else if(price[v]==price[u]+c)
                {

                    ways[v]=(ways[v]+ways[u])%1000000007;
                   // cout<<"\t ways [ "<<v<<"]= "<<ways[v]<<endl;
                    maxFlights[v]=max(maxFlights[v],maxFlights[u]+1);
                    minFlights[v]=min(minFlights[v],minFlights[u]+1);

                }
                //cout<<"\t ways "<<v<<" = "<<ways[v]<<endl;
            }
        }
    }


    cout<<price[n]<<' ';
    cout<<ways[n]<<' '<<minFlights[n]<<' '<<maxFlights[n];
    return 0;
}
