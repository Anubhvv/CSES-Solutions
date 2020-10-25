#include <bits/stdc++.h>
#define loop(i,a,n) for(long long i=a;i<n;++i)
int sumWays[70000][501];
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    loop(i,0,n+1)
        sumWays[0][i]=1;
    int half_sum=(n*(n+1))/2;
    if(half_sum&1)
        cout<<0;
    else
    {
        half_sum=half_sum>>1;
        loop(i,1,n+1)
        loop(j,1,half_sum+1)
        {
            sumWays[j][i]=sumWays[j][i-1];
            if(j>=i)
                sumWays[j][i]=(sumWays[j][i]+sumWays[j-i][i-1])%1000000007;
        }
        printf("%d", sumWays[half_sum][n-1] );
    }
    return 0;
}
