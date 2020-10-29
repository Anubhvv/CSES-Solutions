#include <bits/stdc++.h>
#define loop(i, a, n) for(long long i = a; i < n; ++i)
int n,m,endi,endj;
bool grid[1001][1001],visited[1001][1001];
int distances[1001][1001];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char path[1001][1001];
using namespace std;
bool isInBounds(int x, int y)
{
    if(x<0 or x>=n or y<0 or y>=m)
        return false;
    if( grid[x][y])
        return true;
    return false;
}
int main()
{
    scanf("%d %d", & n, & m);
    char c[1001];
    int sti=-1,stj=-1;
    loop(i,0,n)
    {
        scanf("%s",c);
        loop(j,0,m)
        {
            if(c[j]=='.')
                grid[i][j]=1;
            else if(c[j]=='A')
            {
                sti=i;
                stj=j;
                grid[i][j]=1;
            }
            else if(c[j]=='B')
            {
                endi=i;
                endj=j;
                grid[i][j]=1;
            }

        }
    }
    bool possible=0;
    queue < pair< int, int > > nodesQueue;
    nodesQueue.push(make_pair(sti,stj));
    visited[sti][stj]=true;
    while(! nodesQueue.empty())
    {
         int currentx=nodesQueue.front().first;
         int currenty=nodesQueue.front().second;

         if(currentx==endi and currenty==endj)
            possible=true;

         nodesQueue.pop();

         loop(i,0,4)
         {
             if( isInBounds( currentx+dir[ i ][ 0 ] , currenty+dir[ i ][ 1 ] ) and !visited[currentx+dir[ i ][ 0 ]][currenty+dir[ i ][ 1 ]] )
             {
                 nodesQueue.push(  make_pair( currentx+dir[ i ][ 0 ] , currenty+dir[ i ][ 1 ] )  );
                 distances[ currentx+dir[ i ][ 0 ] ][ currenty+dir[ i ][ 1 ] ]=1+distances[ currentx ][ currenty ];
                 switch(i)
                 {
                 case 0:path[currentx+dir[i][0]][currenty+dir[i][1]]='D';break;
                 case 1:path[currentx+dir[i][0]][currenty+dir[i][1]]='U';break;
                 case 2:path[currentx+dir[i][0]][currenty+dir[i][1]]='R';break;
                 case 3:path[currentx+dir[i][0]][currenty+dir[i][1]]='L';break;
                 }
                 visited[currentx+dir[ i ][ 0 ]][currenty+dir[ i ][ 1 ]]=true;
             }
         }
    }
    if(possible)
    {
        cout<<"YES\n"<<distances[endi][endj]<<'\n';
        int x=endi,y=endj;
        char shortestPath[1000001];

        int i=0;
        while( !(x==sti and y==stj) )
        {
            shortestPath[i]=path[x][y];
            switch(shortestPath[i])
            {
            case 'U':++x; break;
            case 'D':--x; break;
            case 'L':++y; break;
            case 'R':--y; break;
            }
            ++i;
        }
    for(int j=0;j<distances[endi][endj];++j)
        cout<<shortestPath[distances[endi][endj]-j-1];  //printing in reverse
    }
    else cout<<"NO";
    return 0;
}
