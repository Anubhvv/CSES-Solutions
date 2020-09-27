n=int(input())
while n>1:
    print(n,end=' ')
    if(n%2):n=3*n+1 
    else:n//=2
print('1')