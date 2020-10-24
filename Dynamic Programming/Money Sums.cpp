#include <bits/stdc++.h>
#define loop(i,a,n) for(long long i=a;i<n;++i)
bool money[100001][101];
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int coins[n+1];
    loop(i,1,n+1)
        scanf("%d",coins+i);
    int max_money=0;
    loop(i,1,n+1)
        max_money+=coins[i];
    loop(i,0,n+1)
        money[0][i]=1;
    vector < int > sums;
    loop(j,1,max_money+1)
    {
        bool flag=1;
        loop(i,1,n+1)
        {
            money[j][i]=money[j][i-1]|money[j][i];
            if(j>=coins[i])
                money[j][i]=money[j-coins[i]][i-1]|money[j][i];
            if(money[j][i] and flag)
            {
                sums.push_back(j);
                flag=0;
            }
        }
    }
    
    printf("%u\n",sums.size());
    
    loop(i,0,sums.size())
        printf("%d ",sums[i]);
    return 0;
}
