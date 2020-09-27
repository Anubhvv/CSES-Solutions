n=int(input())
l,a=[int(i) for i in input().split()],0
for i in range(1,n):
    if(l[i]<l[i-1]):a,l[i]=a+l[i-1]-l[i],l[i-1]
print(a)
