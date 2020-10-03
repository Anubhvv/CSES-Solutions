#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
bool vis[7][7]={0};
int ans;
char s[50];

bool wall(int i,int j)
{
    if( ( i>0 && i<6 ) && vis[i+1][j] && vis[i-1][j] && (!vis[i][j-1] && !vis[i][j+1]) && j>0 && j<6 )
        return 1;
    else if( ( j>0 && j<6 ) && vis[i][j+1] && vis[i][j-1] && ( !vis[i-1][j] && !vis[i+1][j] ) && i>0 && i<6 )
        return 1;
    else if( i==0 && !vis[i][j-1] && !vis[i][j+1] && j>0 && j<6)//&& vis[i+1][j] )
        return 1;
    else if( j==0 && !vis[i-1][j] && !vis[i+1][j] && i>0 && i<6)//&& vis[i][j+1] )
        return 1;
    else if( i==6 && !vis[i][j+1] && !vis[i][j-1] && j>0 && j<6)// && vis[i-1][j])
        return 1;
    else if( j==6 && !vis[i+1][j] && !vis[i-1][j] && i>0 && i<6 )//&& vis[i][j-1])
        return 1;

    return 0;
}

void rec(int i , int j,int step)                  //i= up down, j= left right
{
    if(i==6 && j==0)
    {
        if(!(step-48))
            ++ans;
        return;
    }
    else if( step>48 || i<0 || i>6 || j<0 || j>6)// ||
        return;
    else if(vis[i][j])
        return;
    else if(wall(i,j))
   /* else if( ( (i==0|| ((i>0 && i<6)  && vis[i+1][j] && vis[i-1][j])) && (!vis[i][j-1] && !vis[i][j+1]) && j>0 && j<6 )
    ||( (j==0||( ( j>0 && j<6 ) && vis[i][j+1] && vis[i][j-1])) && ( !vis[i-1][j] && !vis[i+1][j] ) && i>0 && i<6 )
    ||( i==6 && !vis[i][j+1] && !vis[i][j-1] && j>0 && j<6)// && vis[i-1][j])
    ||( j==6 && !vis[i+1][j] && !vis[i-1][j] && i>0 && i<6 ) )//&& vis[i][j-1])
      */  return ;
    else if( ! vis[i][j] )
    {
        vis[i][j]=1;
        switch(s[step])
        {
            case 'L':
            {rec(i,j-1,step+1) ; break;}
            case 'R':
            {rec(i,j+1,step+1) ; break;}
            case 'U':
            {rec(i-1,j,step+1) ; break;}
            case 'D':
            {rec(i+1,j,step+1) ; break;}
            case '?':
            {
                rec(i,j-1,step+1) ;
                rec(i,j+1,step+1) ;
                rec(i-1,j,step+1) ;
                rec(i+1,j,step+1) ;
            }
        }
        vis[i][j]=0;
        return;
    }
    else return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;

    rec(0,0,0);
    cout<<ans;
    
    return 0;
}
