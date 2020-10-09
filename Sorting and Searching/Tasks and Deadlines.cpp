#include <bits/stdc++.h>
#define loop(i,n) for(long long  i=0;i<n;++i)
using namespace std;
int main()
{
    long long  n,a,d,current_time=0; //a is duration and d is deadline
    long long reward=0;
    multiset < pair<long long  , long long  > > deadline;
    multiset < pair<long long  , long long  > > :: iterator itr;
    scanf("%lld",&n);
    loop(i,n){
        scanf("%lld %lld",&a,&d);
        deadline.insert( make_pair( a , d )); // sorted by d
    }
    for(itr=deadline.begin();itr!=deadline.end();++itr)
    {
        current_time+=(*itr).first;
        reward+=((*itr).second-current_time);
        //cout<<" time , reward = "<<current_time<<' '<<reward<<endl;
    }
    printf("%lld",reward);
    return 0;
}
