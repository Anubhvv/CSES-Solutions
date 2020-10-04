n,m,k=[int(i) for i in input().split()]
a=[int(i) for i in input().split()]
b=[int(i) for i in input().split()]
a.sort()
b.sort()
j=ans=0
for i in range(0,n):
    while (j<m and b[j]< a[i]-k):j+=1
    if(j<m and a[i]+k>=b[j]):
        j+=1
        ans+=1
print(ans)
