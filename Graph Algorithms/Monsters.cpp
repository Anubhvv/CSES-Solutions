#include <bits/stdc++.h>
#define loop(i, a, n) for(long long i = a; i < n; ++i)

using namespace std;

int n,m,endi,endj;
bool grid[1001][1001],visited[1001][1001],possible;
int distances[1001][1001],monsterDist[1001][1001];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char path[1001][1001];
vector < pair < int, int > > monster;

bool isInBounds(int x, int y)
{
    if(x<0 or x>=n or y<0 or y>=m)
        return false;
    if( grid[x][y] )
        return true;
    return false;
}
void bfsMonster()
{
    queue < pair< int, int > > monsterQueue;
    loop(i,0,monster.size())
    {
        monsterQueue.push(make_pair(monster[i].first, monster[i].second));
        visited[monster[i].first][monster[i].second]=true;
    }
    while(! monsterQueue.empty())
    {
         int currentx=monsterQueue.front().first;
         int currenty=monsterQueue.front().second;
         monsterQueue.pop();
         loop(i,0,4)
         {
             if( isInBounds( currentx+dir[ i ][ 0 ] , currenty+dir[ i ][ 1 ] ) and !visited[currentx+dir[ i ][ 0 ]][currenty+dir[ i ][ 1 ]] )
             {
                 monsterQueue.push(  make_pair( currentx+dir[ i ][ 0 ] , currenty+dir[ i ][ 1 ] )  );
                 if(!monsterDist[ currentx+dir[ i ][ 0 ] ][ currenty+dir[ i ][ 1 ] ])
                    monsterDist[ currentx+dir[ i ][ 0 ] ][ currenty+dir[ i ][ 1 ] ]=1+monsterDist[ currentx ][ currenty ];
                 else monsterDist[ currentx+dir[ i ][ 0 ] ][ currenty+dir[ i ][ 1 ] ]=min(monsterDist[ currentx+dir[ i ][ 0 ] ][ currenty+dir[ i ][ 1 ] ], 1+monsterDist[ currentx ][ currenty ]);
                 visited[currentx+dir[ i ][ 0 ]][currenty+dir[ i ][ 1 ]]=true;
             }
         }
    }
    loop(k,0,n)
    loop(j,0,m)
        if(!monsterDist[k][j])
            monsterDist[k][j]=10000000; //infinity for us
    loop(i,0,monster.size())
        monsterDist[monster[i].first][monster[i].second]=0;
}
void bfsA(int x, int y)
{
    queue < pair< int, int > > nodesQueue;
    nodesQueue.push(make_pair(x,y));
    visited[x][y]=true;
    while(! nodesQueue.empty())
    {
         int currentx=nodesQueue.front().first;
         int currenty=nodesQueue.front().second;
         nodesQueue.pop();
         loop(i,0,4)
         {
             if( isInBounds( currentx+dir[ i ][ 0 ] , currenty+dir[ i ][ 1 ] ) and !visited[currentx+dir[ i ][ 0 ]][currenty+dir[ i ][ 1 ]] )
             {
                 nodesQueue.push(  make_pair( currentx+dir[ i ][ 0 ] , currenty+dir[ i ][ 1 ] )  );
                 distances[ currentx+dir[ i ][ 0 ] ][ currenty+dir[ i ][ 1 ] ]=1+distances[ currentx ][ currenty ];
                 visited[currentx+dir[ i ][ 0 ]][currenty+dir[ i ][ 1 ]]=true;
             }
         }
    }
}
bool isBoundary(int x,int y)
{
    if( x==0 or x==n-1 or y==0 or y==m-1 )
        return true;
    return false;
}
void bfsPathRetrieval( int x, int y )
{
   queue < pair< int, int > > nodesQueue;
    nodesQueue.push(make_pair(x,y));
    visited[x][y]=true;
    while(! nodesQueue.empty())
    {
         int currentx=nodesQueue.front().first;
         int currenty=nodesQueue.front().second;
         if(isBoundary(currentx,currenty))
         {
             endi=currentx;
             endj=currenty;
             possible=true;
             break;
         }
         nodesQueue.pop();
         loop(i,0,4)
         {
             if( isInBounds( currentx+dir[ i ][ 0 ] , currenty+dir[ i ][ 1 ] ) and !visited[currentx+dir[ i ][ 0 ]][currenty+dir[ i ][ 1 ]] )
             {
                 if(distances[currentx+dir[ i ][ 0 ]][currenty+dir[ i ][ 1 ]]<monsterDist[currentx+dir[ i ][ 0 ]][currenty+dir[ i ][ 1 ]])
                {
                    visited[currentx+dir[ i ][ 0 ]][currenty+dir[ i ][ 1 ]]=true;
                    nodesQueue.push(  make_pair( currentx+dir[ i ][ 0 ] , currenty+dir[ i ][ 1 ] )  );
                    switch(i)
                    {
                    case 0:path[currentx+dir[i][0]][currenty+dir[i][1]]='D';break;
                    case 1:path[currentx+dir[i][0]][currenty+dir[i][1]]='U';break;
                    case 2:path[currentx+dir[i][0]][currenty+dir[i][1]]='R';break;
                    case 3:path[currentx+dir[i][0]][currenty+dir[i][1]]='L';break;
                    }
                }
             }
         }
    }
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
            else if(c[j]=='M')
            {
                monster.push_back(make_pair(i,j));
                grid[i][j]=1;
            }
        }
    }


    bfsMonster();

    memset(visited,0,sizeof visited);
    bfsA(sti , stj);
    memset(visited,0,sizeof visited);

    bfsPathRetrieval(sti,stj);
    if(possible)
    {
        printf("YES\n%d\n",distances[endi][endj]);
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
        printf("%c",shortestPath[distances[endi][endj]-j-1]);  //printing in reverse
    }
    else printf("NO");
    return 0;
}
