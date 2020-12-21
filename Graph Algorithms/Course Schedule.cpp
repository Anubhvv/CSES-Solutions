#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;
int n,m;
vector<int> requirements[100001];
bool visited[100001];
int indeg[100001];
stack<int> indeg0;
vector < int > topologOrder;
void fill_inDeg()
{
    loop(i,1,n+1)
    {
        loop(j,0,requirements[i].size())
        {
            ++indeg[requirements[i][j]];
        }
    }
}
bool topSort()
{
    loop(i,1,n+1)
    {
        if(!indeg[i])
        {
            indeg0.push(i);
        }
    }
    if(indeg0.empty())
        return false;

    while(!indeg0.empty())
    {
        int course=indeg0.top();
        topologOrder.push_back(course);
        //cout<<course<<" indeg:"<<indeg[course]<<endl;
        indeg0.pop();
        if(indeg[course])
            return false;
        loop(i,0,requirements[course].size())
        {
            if(!(--indeg[requirements[course][i]]))
                indeg0.push(requirements[course][i]);
        }
    }
    if(topologOrder.size()<n)
        return false;
    return true;
}

int main()
{
    scanf("%d %d", & n, & m);
    int a,b;
    loop(i,0,m)
    {
        scanf("%d %d",&a,&b);
        requirements[a].push_back(b);
    }

    fill_inDeg();
    /*
    cout<<"indeg array:";
    loop(i,1,n+1)
        cout<<indeg[i]<<' ';
    cout<<endl;
    */
    if(!topSort())
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    loop(i,0,n)
        cout<<topologOrder[i]<<' ';
    return 0;
}
