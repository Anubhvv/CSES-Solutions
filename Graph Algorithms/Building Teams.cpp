#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;
vector<int> friends[200001];
bool visited[100001];
bool team[100001];
int main()
{
    int n, m;
    bool impossible=false;
    scanf("%d %d", & n, & m);
    int a,b;
    loop(i,0,m)
    {
        scanf("%d %d",&a,&b);
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    loop(i,1,n+1)
    {
        bool team_number=1;
        if(!visited[i])
        {
            queue < int > Qbfs;
            Qbfs.push(i);
            visited[i]=true;
            team[i]=team_number;
            while(!Qbfs.empty() and !impossible)
            {
                int comp=Qbfs.front();
                team_number=!team[comp];
                Qbfs.pop();
                loop(j,0,friends[comp].size())
                {
                   if(visited[friends[comp][j]]) //check for invalid color
                    {
                        if(team[friends[comp][j]]!=team_number)
                        {
                            impossible=true;
                            break;
                        }
                    }
                    else
                    { //has not been visited yet
                        visited[friends[comp][j]]=true;
                        Qbfs.push(friends[comp][j]);
                        team[friends[comp][j]]=team_number;
                    }
                }
            }
        }
    }

    if(impossible)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    loop(i,1,n+1)
        if(team[i])
            cout<<1<<' ';
        else
            cout<<2<<' ';

    return 0;
}
