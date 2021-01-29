#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;

int adj[200001];
bool vis[200001];
int dis[200001];
//int ancestor[200001][33];   //33>log2(2x10^9)

int main()
{
    int n, q;
    n=6;
    scanf("%d", & n);

    loop(i,1,n+1)
    {
        scanf("%d",&adj[i]);
    }

    loop(i,1,n+1)
    {
        if(!vis[i]){

            int x=i;
            int steps=1;
            int a = adj[x];
            int b = adj[adj[x]];
            int visited=0;
            bool shortcut=0; //some part ids already calculated, we don't calculate again. 7->1>2->3->3 for 7 node, we can use dist[1]+1


            while (a != b)
            {
                if(vis[a])
                {
                    shortcut=1;
                    visited=a;
                    break;
                }
                ++steps;
                a = adj[a];
                b = adj[adj[b]];
            }
            if(vis[a])
            {
                shortcut=1;
                visited=a;
            }

            if(shortcut)//continue bec we dont need to check for cycle etc
            {
                dis[x]=steps+dis[visited];
                printf("%d ",dis[i]);
                continue;
            }


            a = x;
            int linear_len=0;
            while (a != b)
            {
                a = adj[a] ;
                b = adj[b];
                ++linear_len;
            }
            int first = a;
            b = adj[a];
            int len = 1;
            while (a != b)
            {
                b = adj[b];
                len++;
            }
            int cur=adj[first];
            dis[first]=len;
            vis[first]=1;
            while(cur!=first)
            {
                dis[cur]=len;
                vis[cur]=1;
                cur=adj[cur];
            }
            cur=x;

            //if path is like Linear+Cycle
            if(linear_len){
                while(vis[cur]==0)
                {
                    vis[cur]=1;
                    dis[cur]=linear_len+len;
                    --linear_len;
                    cur=adj[cur];
                }
            }

        }
        printf("%d ",dis[i]);
    }
    return 0;
}
