#include <bits/stdc++.h>
#include <array>
#define loop(i,n) for(long long i=0;i<n;++i)
using namespace std;
int main()
{
    int n,k;
    int a,d;
 
    scanf("%d %d",&n,&k);
    multiset < int > depart;
    array < int ,3 > dai[n];
    multiset < int >::iterator itr;
    loop(i,n)
    {
        scanf("%d %d",&a,&d);
        dai[i][0]=d;
        dai[i][1]=a;
    }
    sort(dai,dai+n);
    int ans=0;
    loop(i,n)
    {
        itr=depart.lower_bound(dai[i][1]+1);
        if(itr!=depart.begin())
        {
            --itr;
            depart.erase(itr);
        }
        if(depart.size()<k)
        {
            ++ans;
            depart.insert(dai[i][0]);
        }
    }
    printf("%d",ans);
 
    
