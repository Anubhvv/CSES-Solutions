#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
long long  sum[10000000],s[20],n,tot=0,t=0,temp;
int main() {
    void rec(int,long long );
	cin>>n;
	for(long long  i=0;i <n;i++)
    {
        cin>>s[i];
        tot+=s[i];
    }
    rec(0,0);
    long long  ans=2000000000000;
    for(long long  i=0;i<t;i++)
    {
        temp=2*sum[i]-tot;
        if(temp>=0 )
        {
            if(temp<ans)
                ans=temp;
        }
        else if(-temp<ans)
            ans=-temp;
        if(!ans)
            break;
    }
    cout<<ans;
	return 0;
}
void rec(int  i,long long  sum_)
{
    if( i==n )
    {
        sum[t++]=sum_;
        return;
    }
    rec( i+1, sum_+s[i] );
    rec( i+1, sum_ );
}
