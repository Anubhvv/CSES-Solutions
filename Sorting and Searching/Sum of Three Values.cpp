#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;++i)
using namespace std;
int main()
{
    int n,x,temp;
    bool flag=1;
    scanf("%d %d",&n,&x);
    vector < pair<int , int > > a;
    loop(i,n)
    {
        scanf("%d",&temp);
        a.push_back(make_pair(temp,i+1));
    }
    sort(a.begin(),a.end());
    int v1;
    loop(i,n)
    {
        int j=i+1,k=n-1;
        for(;j<k;)
        {
            if(x>a[i].first+a[j].first+a[k].first)
                ++j;
            else if(x<a[i].first+a[j].first+a[k].first)
                --k;
            else break;
        }
        if(a[i].first+a[j].first+a[k].first==x and j!=k)
        {
            flag=false;
            printf("%d %d %d",a[i].second,a[j].second,a[k].second);
            break;
        }
    }
    if(flag)
        printf("IMPOSSIBLE");
    return 0;
}
