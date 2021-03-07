#include <bits/stdc++.h>
#define loop(i, a, n) for(int i = a; i < n; ++i)

using namespace std;

long long lazy[800001],tree[800001];

void buildSegTree(int s, int e, int np, long long arr[])
{
    if(s==e)
    {
        tree[np]=arr[s];
        return;
    }
    int mid=(s+e)/2;
    buildSegTree(s,mid,2*np+1,arr);
    buildSegTree(mid+1,e,2*np+2,arr);

    tree[np]=tree[2*np+1]+tree[2*np+2];

    return;
}

void updateRange(int node, int start, int end, int l, int r, long long val)
{
   // cout<<"update start , end ="<<start<<','<<end<<endl;
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2+1] += lazy[node];                  // Mark child as lazy
            lazy[node*2+2] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        tree[node] += (end - start + 1) * val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2+1] += val;
            lazy[node*2+2] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2+1, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 2, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = tree[node*2+1] + tree[node*2+2];        // Updating root with max value
}

long long getValue(int node, int start, int end, int index) // l =r = index
{
   // cout<<"start , end = "<<start<<','<<end<<endl;
    if(start > end or start > index or end < index)
        return 0;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2+1] += lazy[node];         // Mark child as lazy
            lazy[node*2+2] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start==end)
    {
        if(start==index)
            return tree[node];
        else return 0;
    }
    if(start <= index and end >= index)             // Current segment is totally within range [l, r]
    {
    int mid = (start + end) / 2;
    long long p1 = getValue(node*2+1, start, mid, index);         // Query left child
    long long p2 = getValue(node*2 + 2, mid + 1, end, index); // Query right child
    return (p1 + p2);}
    return 0;
}

void display(int N,long long tree[],long long lazy[])
{
    cout<<"SEGMENT TREE\n";
    loop(i,0,4*N)
    cout<<tree[i]<<' ';
    cout<<"\n\nLAZY TREE\n";
    loop(i,0,4*N)
    cout<<lazy[i]<<' ';

}

int main()
{
    int n,q,a,b;
    cin>>n>>q;
    long long arr[n];

    loop(i,0,n)
        cin>>arr[i];
    loop(i,0,4*n)
        lazy[i]=0;
    buildSegTree(0, n-1, 0, arr);
  //  display(n,tree,lazy);
    while(q--)
    {

        int type;
        cin>>type;
       // display(n,tree,lazy);
        if(type==2)
        {
            int k;
            cin>>k;
            --k;
            //cout<<"\n\nANS2-";
            cout<<getValue(0,0,n-1,k)<<endl;
          //  display(n,tree,lazy);
        }
        else{
            long long u;
            cin>>a>>b>>u;
            --a;--b;
            updateRange(0,0,n-1,a,b,u);
           // display(n,tree,lazy);
        }
    }
    return 0;
}
