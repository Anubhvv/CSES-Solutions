#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;
int link[100001],size[100001];

int find(int x)
{
    while(x!=link[x])
        x=link[x];
    return x;
}


bool same(int a,int b)
{
    if(find(a)==find(b))
        return true;
    return false;
}

void unite(int a,int b)
{
    a=find(a);
    b=find(b);
    if(size[a]<size[b])
    {
        swap(a,b);
    }
    size[a]+=size[b];
    link[b]=a;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector< pair< long long, pair < int , int > > >ascWt;
    loop(i,1,m+1)
    {
        int a,b;
        long long c;
        cin>>a>>b>>c;
        ascWt.push_back(make_pair(c, make_pair(a,b)));
    }
    sort(ascWt.begin(),ascWt.end());
    loop(i,1,n+1)
    {
        link[i]=i;
        size[i]=1;
    }
    long long min_cost=0;
    loop(i,0,m)
    {
        long long c=ascWt[i].first;
        int a=ascWt[i].second.first;
        int b=ascWt[i].second.second;
        if (!same(a,b))
        {
            unite(a,b);
            min_cost+=c;
        }
    }

    if(size[find(1)]==n)
        cout<<min_cost;
    else cout<<"IMPOSSIBLE";
    return 0;
}
