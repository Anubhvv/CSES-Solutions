#include <bits/stdc++.h>
#define loop(i,n) for(long long i=0;i<n;++i)
using namespace std;
int main()
{
    long long n,k;
    long long a,d;

    scanf("%lld %lld",&n,&k);
    multiset <pair < long long ,long long > >arrival;
    multiset < pair < long long, long long > >depart;
    vector < pair < long long, long long > > sch;
    //map<int, int > room;
    multiset < pair < long long, long long > >::iterator itr;
    loop(i,n)
    {
        scanf("%lld %lld",&a,&d);
        sch.push_back(make_pair(a,d));
        arrival.insert(make_pair(a,i));
        depart.insert(make_pair(d,i));
    }
    //int ans=0;
    long long guest=0;
    //int room_num=0;
    long long ans=0;
    while(arrival.size() and depart.size() and guest<k)
    {
       // ++room_num;
       ++guest;
        long long arr,ind,dept;
        itr=depart.begin();
        while(true)
        {
            dept=(*itr).first;
            ind=(*itr).second;
            //cout<<" dept  = "<< dept << endl;
 //++ans;
            depart.erase(itr);
            ++ans;
            //cout<<"room["<<ind<<"]="<<room_num<<endl;
            //room[ind]=room_num;
            //++ans;
            arr=sch[ind].first;
            //cout<<"arr = " << arr <<endl;

            arrival.erase(arrival.find(make_pair(arr,ind)));
            itr=arrival.lower_bound(make_pair( dept,0  ));
            //itr=depart.lower_bound(make_pair(dept,10000000));
            if(itr==arrival.end())
                break;
            ind=(*itr).second;
            dept=sch[ind].second;
            itr=depart.lower_bound(make_pair( dept,ind));
            if(itr==depart.end())
                break;
           // ++ans;
          //  ++itr;
          //  cout<<" lower bound ("<<arr<<", "<<ind<<") = "<<(*itr).first<<' '<<(*itr).second<<endl;
        }
    }
    printf("%lld",ans);
    //cout<<ans<<endl;

    return 0;
}
