#include <bits/stdc++.h>
#define loop(i, a, n) for(long long i = a; i < n; ++i)
int n,m;
bool grid[1001][1001];
using namespace std;
void destroy_room(int i,int j)
{
    if(i<0 or j<0 or i>=n or j>=m)
        return;
    if( grid[i][j] )
    {
        grid[i][j]=0;
        destroy_room(i+1,j);
        destroy_room(i-1,j);
        destroy_room(i,j+1);
        destroy_room(i,j-1);
    }

    else return;
}
int main()
{
    scanf("%d %d", & n, & m);
    char c[1001];
    loop(i,0,n)
    {
        scanf("%s",c);
        loop(j,0,m)
        {
            if(c[j]=='.')
                grid[i][j]=1;
        }
    }
    int room=0;
    loop(i,0,n)
    loop(j,0,m)
    {
        if(grid[i][j])
        {
            destroy_room(i,j);
            ++room;
        }
    }
    printf("%d", room);
    return 0;
}
