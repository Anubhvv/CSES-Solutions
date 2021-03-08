#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;
void buildSegTree(int s, int e, int np, bool arr[],int tree[])
{
    if(s==e)
    {
        if(arr[s]==true)
            tree[np]=1;
        else tree[np]=0;
        return;
    }

    int mid=(s+e)/2;
    buildSegTree(s,mid,2*np+1,arr,tree);
    buildSegTree(mid+1,e,2*np+2,arr,tree);

    tree[np]=tree[2*np+1]+tree[2*np+2];

    return;
}

int getSum(int a,int b,int np,int left, int right, int tree[])
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
        long long leftSUM=getSum(a,b,2*np+1,left,mid, tree);
        long long rightSUM=getSum(a,b,2*np+2,mid+1,right,tree);
        //cout<<leftMIN<<"        "<<rightMIN<<endl;
        return leftSUM+rightSUM;
    }
}

void Update(int index,int val,int np,int left,int right,int tree[])
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
        Update(index,val,2*np+1,left,mid,tree);
    }
    else{
        Update(index,val,2*np+2,mid+1,right,tree);
    }
    leftSUM=tree[2*np+1];
    rightSUM=tree[2*np+2];
    tree[np]=leftSUM+rightSUM;
    return;
}
int BinarySearch(int p, bool present[],int tree[],int n)
{
    int left=0,right=n-1;
    while(left<=right)
    {
        //cout<<"\n mid = " <<mid<<endl;
        int mid=left+(-left+right)/2;
        //cout<<"\n mid = " <<mid<<endl;
        int uptoSum=getSum(0,mid, 0,0,n-1,tree);
        //cout<<"uptosum ="<<uptoSum<<endl;
        if(uptoSum>p)
        {
            right=mid-1;
        }
        else if(uptoSum<p)
        {

            left=mid+1;
           // cout<<"left=mid+1="<<left<<endl;
        }
        else{
            if(present[mid])
                return mid;
            else right=mid-1;
        }
    }
    return -1;
}
void display(int n,int tree[])
{
    cout<<"\ntree:\n";
    loop(i,0,4*n)
    cout<<tree[i]<< ' ';
}
int main()
{
    int n;
    cin>>n;
    int x[n];
    bool present[n];
    int tree[4*n];
    loop(i,0,n)
    {
        cin>>x[i];
        present[i]=true;
    }
    buildSegTree(0, n-1, 0, present,tree);
    loop(i,0,n)
    {
        int p;
        cin>>p;
       // display(n,tree);
        int index=BinarySearch(p,present,tree,n);
        //cout<<"binary index = "<<index<<endl;
        //cout<<"\n\nans===";
        cout<<x[index]<<' ';
        Update(index,0,0,0,n-1,tree);
        present[index]=0;
        //display(n,tree);
    }
    return 0;
}
