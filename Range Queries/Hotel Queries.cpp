#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;
void buildSegTree(int s, int e, int np, int arr[],int tree[])
{
    if(s==e)
    {
        tree[np]=arr[s];
        return;
    }

    int mid=(s+e)/2;
    buildSegTree(s,mid,2*np+1,arr,tree);
    buildSegTree(mid+1,e,2*np+2,arr,tree);

    if(tree[2*np+1]>tree[2*np+2])
        tree[np]=tree[2*np+1];
    else tree[np]=tree[2*np+2];

    return;
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
    tree[np]=max(leftSUM,rightSUM);
    return;
}

int getHotel(int rooms, int node, int left, int right, int tree[],int h[])
{
    //cout<<"left right ="<<left<<' '<<right<<endl;
    if(rooms>tree[node])
    {
      //  cout<<1<<endl;
        return 0;
    }
    if(left==right)
    {
        //cout<<3<<endl;
      //  cout<<"tree["<<node<<"] = "<<tree[node]<<endl;
      //  cout<<"returning "<<left+1<<endl;
        return left+1;
    }

          //  cout<<4<<endl;
    int mid=(left+right)/2;
    int  leftMAX=getHotel(rooms,2*node+1,left,mid,  tree,h);
        //int  rightMAX=getHotel(rooms,2*node+2,mid+1,right,tree);
        //cout<<leftMIN<<"        "<<rightMIN<<endl;
    //cout<<"\tleftmax["<<left<<","<<mid<<"]="<<leftMAX<<'\t';
    if(leftMAX>=1 and h[leftMAX-1]>=rooms)
        return leftMAX;

    int  rightMAX=getHotel(rooms,2*node+2,mid+1,right,tree,h);
    //cout<<"\trightmax["<<mid+1<<","<<right<<"]="<<rightMAX<<endl;

    if(rightMAX>=1 and h[rightMAX-1]>=rooms)
        return rightMAX;

    return 0;

}
void display(int n,int tree[])
{
    cout<<"\ntree:\n";
    loop(i,0,4*n)
    cout<<tree[i]<< ' ';
}
int main()
{
    int n,m;
    cin>>n>>m;
    int  h[n],r[m],tree[4*n];
    loop(i,0,n)
        cin>>h[i];
    loop(i,0,m)
        cin>>r[i];
    buildSegTree(0, n-1, 0, h, tree);
    //display(n,tree);
    loop(i,0,m)
    {
       int hotelNumber=getHotel(r[i], 0, 0, n-1,tree,h);
       cout<<hotelNumber<<' ';
       if(hotelNumber)
       {
          // cout<<"val update = "<<h[hotelNumber-1]-r[i]<<endl;
            Update(hotelNumber-1,h[hotelNumber-1]-r[i],0,0,n-1,tree);
            h[hotelNumber-1]-=r[i];
          //  display(n,tree);
       }
    }
    return 0;
}
