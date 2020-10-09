#include <bits/stdc++.h>
#define loop(i,n) for(long long  i=0;i<n;++i)
using namespace std;
long long  k[200001];
long long  n,t;
long long  binarySearch(long long  l,long long  r,long long  x)
{
   if (r >= l) {
        long long  mid = l + (r - l) / 2;
        long long  num_prod=0,prev_prod=0;

        loop(i,n){
            num_prod+=mid/k[i];
            if(num_prod>x)
                break;
        }
        loop(i,n)
        {
            prev_prod+=(mid-1)/k[i];
            if(prev_prod>x)
                break;
        }
        if (num_prod == x)
            {
                if(prev_prod<x)
                    return mid;
                else return binarySearch(l,mid-1,x);
            }
        else if (num_prod > x and prev_prod<x)
            return mid;

        else if(num_prod > x)
            return binarySearch( l, mid - 1, x);
        return binarySearch( mid + 1, r, x);
    }
    return -1;
}
int main()
{
    scanf("%lld %lld",&n,&t);
    loop(i,n)
        scanf("%lld",k+i);
    printf("%lld",binarySearch(1,1000000000000000000,t));
    return 0;
}
