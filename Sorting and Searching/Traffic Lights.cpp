//Time Limit Exceeding for big test cases. Idk why, this algo is O(nlogn)
//UPDATE: Code Accepted, Time 0.70 s, std lower_bound is O(n) while set_name.lower_bound is O(log(n))
#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;++i)
using namespace std;
int main()
{
    int x,n,a;
    scanf("%d %d",&x,&n);
    set <int> traffic;
    multiset <int> distance;
    set <int>::iterator itr;
    int left,right;
    traffic.insert(0);
    traffic.insert(x);
    distance.insert(x);
    loop(i,n)
    {
        scanf("%d",&a);
      //  itr=lower_bound(traffic.begin(),traffic.end(),a);
        itr=traffic.lower_bound(a);
        right=(*itr);
        left= *(--itr);
 
        traffic.insert( a );
 
        if(distance.find(right-left)!=distance.end())
            distance.erase(distance.find(right-left));
 
        distance.insert(right-a);
        distance.insert(a-left);
 
        printf("%d \n",*(--distance.end()));
 
    }
