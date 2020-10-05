#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
    vector < pair<int,int> > sch;
    int n,a,b;
    scanf("%d",&n);
    loop(i,n)
    {
        scanf("%d %d",&a,&b);
        sch.push_back(make_pair(a,1));
        sch.push_back(make_pair(b,-1));
    }
    sort(sch.begin(),sch.end());
    int c=0,maxc=0;
    loop(i,2*n)
    {
        --c;
       if(sch[i].second>0)
            c+=2;
       if(c>maxc)
        maxc=c;
    }
    printf("%d",maxc);
    return 0;
}
