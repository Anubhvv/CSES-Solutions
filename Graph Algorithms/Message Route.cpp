#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;
vector<int> compNet[200001];
bool visited[100001];
int dist[100001];
int path[100001];

int main()
{
    int n, m;
    scanf("%d %d", & n, & m);
    int a,b;
    loop(i,0,m)
    {
        scanf("%d %d",&a,&b);
        compNet[a].push_back(b);
        compNet[b].push_back(a);
    }
    queue < int > Qbfs;
    Qbfs.push(1);
    visited[1]=true;
    dist[1]=1;
    while(!Qbfs.empty())
    {
        int comp=Qbfs.front();
        Qbfs.pop();
        loop(i,0,compNet[comp].size())
        {
            if(!visited[compNet[comp][i]])
            {
                visited[compNet[comp][i]]=true;
                dist[compNet[comp][i]]=1+dist[comp];
                path[compNet[comp][i]]=comp;
                Qbfs.push(compNet[comp][i]);
            }
        }
    }
    if(dist[n])
    {
    cout<<dist[n]<<endl;

    int rev_path[dist[n]];
    int i=n;
    int k=0;
    //reversing the path
    rev_path[k++]=n;
    while(i!=1)
    {
        rev_path[k++]=path[i];
        i=path[i];
    }
    //printing the final path
    loop(j,0,dist[n])
        printf( "%d " , rev_path[ dist[ n ]-j-1 ] );
    return 0;
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
