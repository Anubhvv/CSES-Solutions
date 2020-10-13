#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;++i)
using namespace std;
int x[200001];
multiset<int> lower,higher;
void insertHeap(int item)
{
    if(higher.size())
    {
        if(item>=(*higher.begin()))
            higher.insert(item);
        else lower.insert(item);
    }
    else if(lower.size())
    {
        if(item<=(*lower.rbegin()))
            lower.insert(item);
        else higher.insert(item);
    }
    else lower.insert(item);
}
void deleteHeap(int item)
{
    if(lower.size())
    {
        if(!higher.size())
            lower.erase(lower.find(item));
        else{
            if(item>(*lower.rbegin()))
                higher.erase(higher.find(item));
            else lower.erase(lower.find(item));
        }
    }
    else
    {
        higher.erase(higher.find(item));
    }
}
void balanceHeap()
{
    if(lower.size()> higher.size()+1)
    {
        higher.insert((*(lower.rbegin())));
        lower.erase(--lower.end());
    }
    else if ( lower.size()+1< higher.size() )
    {
        lower.insert((*higher.begin()));
        higher.erase(higher.begin());
    }
}
int findMedian()
{
    if(lower.size()>=higher.size())
        return (*(lower.rbegin()));
    else if (lower.size()<higher.size())
        return (*(higher.begin()));
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    loop(i,n)
    {
        scanf("%d",x+i);
    }
    loop(i,k)
    {
        insertHeap(x[i]);
        balanceHeap();
    }
    printf("%d ",findMedian());
    for(int i=1;i<n-k+1;++i)
    {
       deleteHeap(x[i-1]);
       balanceHeap();
       insertHeap(x[i+k-1]);
       balanceHeap();
       printf("%d ",findMedian());
    }
    return 0;
}
