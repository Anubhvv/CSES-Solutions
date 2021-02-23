#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)
#define mod 1000000007
#define inf 1000000000000000;
using namespace std;

void buildSegTree(int s, int e, int np, long long arr[],long long tree[])
{
    if(s==e)
    {
        tree[np]=arr[s];
        return;
    }

    int mid=(s+e)/2;
    buildSegTree(s,mid,2*np+1,arr,tree);
    buildSegTree(mid+1,e,2*np+2,arr,tree);

    tree[np]=tree[2*np+1]+tree[2*np+2];

    return;
}

void Update(int index,long long val,int np,int left,int right,long long arr[],long long tree[])
{
    //cout<<" index    left, right = "<<index<<"     "<<left<<","<<right<<endl;
    if(left==right)
    {
        tree[np]=val;
      //  cout<<"np="<<np<<endl;
        //cout<<"val="<<val<<endl;
        return;
    }
    int mid=(left+right)/2;
    long long leftSUM,rightSUM;
    if(index<=mid)
    {
        Update(index,val,2*np+1,left,mid,arr,tree);
    }
    else{
        Update(index,val,2*np+2,mid+1,right,arr,tree);
    }
    leftSUM=tree[2*np+1];
    rightSUM=tree[2*np+2];
    tree[np]=leftSUM+rightSUM;
    return;
}
long long getSum(int a,int b,int np,int left, int right, long long arr[],long long tree[])
{
    //cout<<" a,b  left, right = "<<a<<","<<b<<" "<<left<<","<<right<<endl;
    if(left>b or right<a)
    {
      //  cout<<1<<endl;
        return 0;
    }
   else if(a<=left and right<=b)
    {
        //cout<<3<<endl;
        return tree[np];
    }
    else {
          //  cout<<4<<endl;
        int mid=(left+right)/2;
        long long leftSUM=getSum(a,b,2*np+1,left,mid, arr, tree);
        long long rightSUM=getSum(a,b,2*np+2,mid+1,right,arr ,tree);
        //cout<<leftMIN<<"        "<<rightMIN<<endl;
        return leftSUM+rightSUM;
    }
}

int main()
{
    int n,q,a,b;
    cin>>n>>q;
    long long arr[n], tree[4*n];
    loop(i,0,n)
        cin>>arr[i];
    buildSegTree(0, n-1, 0, arr, tree);
    while(q--)
    {
        int type;
        cin>>type;
        if(type==2){
            cin>>a>>b ;
            --a;--b;
            cout<<getSum(a,b,0,0,n-1,arr,tree)<<'\n';
        }
        else{
            int index;
            long long val;
            cin>>index>>val;
            --index;
            Update(index,val,0,0,n-1,arr,tree);
        }
    }
    return 0;
}
