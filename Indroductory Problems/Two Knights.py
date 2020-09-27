k=int(input()) 
for i in range(1,k+1):
    if i>=3:print(int((i*i*(i*i-1))/2)-(2*i-3)*(2*i-3)+1)
    else:print(int((i*i*(i*i-1))/2))
