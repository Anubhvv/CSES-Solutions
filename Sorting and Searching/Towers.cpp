#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;++i)
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a,ind;
    vector <int > towers;
    loop(i,n)
    {
        scanf("%d",&a);
        ind=upper_bound(towers.begin(),towers.end(),a)-towers.begin();
        if(ind<towers.size())
            towers[ind]=a;
        else towers.push_back(a);
        vector <int>::iterator it;
    }
    printf("%d",towers.size());
    return 0;
}
