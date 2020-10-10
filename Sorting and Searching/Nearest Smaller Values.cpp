#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;++i)
using namespace std;
int main()
{
    int n,temp;
    scanf("%d",&n);
    int x[n],left[n];
    loop(i,n)
    {
        scanf("%d",x+i);
        left[i]=i-1;
        while ( left[i]>=0 and x[left[i]]>=x[i])
          left[i]=left[left[i]];
        printf("%d ",left[i]+1);
    }
    return 0;
}
