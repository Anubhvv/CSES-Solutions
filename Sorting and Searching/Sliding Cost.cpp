#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;++i)
using namespace std;
long long x[200001],left_sum=0,right_sum=0;
multiset<long long > lower,higher;
void insertHeap(long long item)
{
    if(higher.size())
    {
        if(item>=(*higher.begin()))
        {
            right_sum+=item;
            higher.insert(item);
        }
        else
        {
            left_sum+=item;
            lower.insert(item);
        }
    }
    else if(lower.size())
    {
        if(item<=(*lower.rbegin()))
        {
            left_sum+=item;
            lower.insert(item);
        }
        else
        {
            right_sum+=item;
            higher.insert(item);
        }
    }
    else
    {
        left_sum+=item;
        lower.insert(item);
    }
}
void deleteHeap(long long item)
{
    if(lower.size())
    {
        if(!higher.size())
            {
                left_sum-=item;
                lower.erase(lower.find(item));
            }
        else{
            if(item>(*lower.rbegin()))
            {
                right_sum-=item;
                higher.erase(higher.find(item));
            }
            else
            {
                left_sum-=item;
                lower.erase(lower.find(item));
            }
        }
    }
    else
    {
        right_sum-=item;
        higher.erase(higher.find(item));
    }
}
void balanceHeap()
{
    if(lower.size()> higher.size()+1)
    {
        higher.insert((*(lower.rbegin())));
        right_sum+=(*(lower.rbegin()));
        left_sum-=(*lower.rbegin());
        lower.erase(--lower.end());
    }
    else if ( lower.size()+1< higher.size() )
    {
        lower.insert((*higher.begin()));
        left_sum+=(*higher.begin());
        right_sum-=(*higher.begin());
        higher.erase(higher.begin());
    }
}
long long findMedian()
{
    if(lower.size()>=higher.size())
        return (*(lower.rbegin()));
    else if (lower.size()<higher.size())
        return (*(higher.begin()));
}
long long costODD(long long med)
{
        if(lower.size()>=higher.size())
            return right_sum-left_sum+med;
        else return right_sum-left_sum-med;
}
long long costEVEN()
{
    return right_sum-left_sum;
}

void summation()
{
     multiset<long long> ::iterator itr;
    long long left_sum=0,right_sum=0;
    for(itr=lower.begin();itr!=lower.end();++itr)
        left_sum+= (*itr);
    for(itr=higher.begin();itr!=higher.end();++itr)
        right_sum+= (*itr);
}

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    loop(i,n)
        scanf("%lld",x+i);
    loop(i,k)
    {
        insertHeap(x[i]);
        balanceHeap();
    }
    summation();
    if(k&1)
    printf("%lld ",costODD(findMedian()));
    else printf("%lld ",costEVEN());
    if(k&1)
    for(int i=1;i<n-k+1;++i)
    {
       deleteHeap(x[i-1]);
       balanceHeap();
       insertHeap(x[i+k-1]);
       balanceHeap();

       printf("%lld ",costODD(findMedian()));
    }
    else
    {
        for(int i=1;i<n-k+1;++i)
        {
            deleteHeap(x[i-1]);
            balanceHeap();
            insertHeap(x[i+k-1]);
            balanceHeap();

            printf("%lld ",costEVEN());
        }
    }
    return 0;
}
