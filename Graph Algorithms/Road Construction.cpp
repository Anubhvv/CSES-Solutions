#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;

int link[100001],size[100001];
int max_size=0;
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
    max_size=max(max_size,size[a]);

    link[b]=a;
}


int main()
{
    int n,m;
    cin>>n>>m;
    int conn=n;
    vector< pair<int, int> > roads; //queue can also be used
    loop(i,1,m+1)
    {
        int a,b;
        cin>>a>>b;
        roads.push_back(make_pair(a,b));
    }
    loop(i,1,n+1)
    {
        link[i]=i;
        size[i]=1;
    }
    loop(i,0,roads.size())
    {
        int a=roads[i].first;
        int b=roads[i].second;
        if(!same(a,b))
        {
            unite(a,b);
            --conn;
        }
        cout<<conn<<' '<<max_size<<endl;
    }
    return 0;
}
