n,s=int(input()),''
if(n<=3 and n>1): s='NO SOLUTION'
else: 
    i=1
    if(n%2==0):
        while i<=n//2:
            s+=str(i)+' '+str(n//2+i)+' '
            i+=1
    if n==4:s='2 4 1 3'
    else:
        while i<=n//2:
            s+=str(i)+' '+str(n//2+1+i)+' '
            i+=1
        s+=str(n//2+1)
print(s) 
