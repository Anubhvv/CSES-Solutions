n=int(input())
l,di=[int(i) for i in input().split()],{}
for i in l:di[i]=0
for i in l:di[i]+=1
print(len(di))