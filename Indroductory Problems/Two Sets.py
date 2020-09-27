k=int(input())
if k%4==0 or (k+1)%4==0:
    print('YES')
    if(k%2==0):
        print(k//2)
        i=1
        s1=''
        while i<=k//2:
            s1+=str(i)+' '+str(k-i+1)+' '
            i+=2
        print(s1)
        print(k//2)
        i=2
        s2=''
        while i<=k//2:
            #print(i,' ',k-i+1,end=' ')
            s2+=str(i)+' '+str(k-i+1)+' '
            i+=2
        print(s2)
    else:
        print(k//2+1)
        i=1
        s1='1 2 '
        s2='3 '
        i=1
        #print(s1,end=' ')
        k=k-3
        while i<=(k)//2:
            s1+=str(i+3)+' '+str(k-i+1+3)+' '
            i+=2
        i=2
        print(s1)
        print((k+3)//2)
        while i<=(k)//2:
            s2+=str(i+3)+' '+str(k-i+1+3)+' '
            i+=2  
        print(s2)  
else: print('NO')
