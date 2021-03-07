#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;
char forest[1000][1000];
int forestCount[1000][1000];
void fillForestCount(int n)
{
    loop(i,1,n+1)
    loop(j,1,n+1)
    {
        int left,up,leftUp;

        left=forestCount[i][j-1];
        up=forestCount[i-1][j];
        leftUp=forestCount[i-1][j-1];

        forestCount[i][j]=left+up-leftUp;

        if(forest[i][j]=='*')
            ++forestCount[i][j];
    }
}
int main()
{
    int n,q;
    cin>>n>>q;
    loop(i,1,n+1) //i=y
    loop(j,1,n+1) //j=x
        cin>>forest[i][j];
    fillForestCount(n);
    /*
    loop(i,0,n+1) //i=y
    {
        loop(j,0,n+1) //j=x
            cout<<forestCount[i][j]<<' ';
        cout<<endl;
    }*/
    while(q--)
    {
        int x1,x2,y1,y2;
        cin>>y1>>x1>>y2>>x2;
        int rightDown,left,up,leftUp;

        rightDown=forestCount[y2][x2];
        left=forestCount[y2][x1-1];
        up=forestCount[y1-1][x2];
        leftUp=forestCount[y1-1][x1-1];

        cout<<rightDown+leftUp-up-left<<endl;
    }
    return 0;
}
