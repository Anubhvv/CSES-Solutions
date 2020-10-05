#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;++i)
using namespace std;
int main()
{
    vector < pair<int,int> > sch;
    int n,a,b;
    scanf("%d",&n);
    loop(i,n)
    {
        scanf("%d %d",&a,&b);
        sch.push_back(make_pair(b,a));
    }
    sort(sch.begin(),sch.end());
    int ex=-1,movie=0;
    loop(i,n)
    {
        if(ex<=sch[i].second)
        {
            ex=sch[i].first;
            ++movie;
        }
    }
    printf("%d",movie);
    return 0;
}
