#include <bits/stdc++.h>
#define loop(i,a,n) for(long long i=a;i<n;++i)
using namespace std;
int main()
{
    int n,x;
    vector <int> sorted_longest;
    vector<int> ::iterator itr;
    scanf("%d",&n);
    loop(i,0,n)
    {
        scanf("%d",&x);
        itr=lower_bound(sorted_longest.begin(),sorted_longest.end(),x);
        if(itr==sorted_longest.end())
            sorted_longest.push_back(x);
        else *itr=x;
    }
    printf("%d",sorted_longest.size());
    return 0;
}
