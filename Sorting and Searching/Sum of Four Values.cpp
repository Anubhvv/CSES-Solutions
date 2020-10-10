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
    for(int i=0;i<n-3 and flag; i++)
    {
        int j =i+1,k,l;
        for(;j<n-2;++j)
        {
            k=j+1;
            l=n-1;
            while(k<l)
            {
                if( x < a[i].first+a[j].first+a[k].first+a[l].first )
                --l;
                else if(x>a[i].first+a[j].first+a[k].first+a[l].first)
                ++k;
                else break;

            }
            if( x== (a[i].first+a[j].first+a[k].first+a[l].first) and k!=l)
            {
                flag=false;
                printf("%d %d %d %d",a[i].second,a[j].second,a[k].second,a[l].second );
                break;
            }
        }
    }
    if(flag)
        printf("IMPOSSIBLE");
    return 0;
}
