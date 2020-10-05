#include <bits/stdc++.h>
using namespace std;

int t[10000000],n,m; //n-tickets

int main()
{
    multiset <int > h;
    int x;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        h.insert(x);
    }
    for(int i=0;i<m;i++)
        scanf("%d",&t[i]);
    multiset<int>::iterator ind;
    for(int i=0 ;i < m ; i++ )
    {
          if(h.empty())
          {
              printf("%d\n",-1);
              continue;
          }
         ind=h.lower_bound(t[i]);
         if(ind==h.begin() and *ind!=t[i])
            ;
         else if(*ind!=t[i])
            --ind;
        if(*ind<=t[i])
        {
            printf("%d\n",*ind);

            h.erase(ind);
        }
        else printf("%d\n",-1);
    }

    return 0;
}
