s=int(input())+1
n,l=input().split(),[0]*s
for i in n:l[int(i)]=1
for i in range(1,s):
    if l[i]==0:print(i)
