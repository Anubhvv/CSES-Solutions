d,m,t=input(),1,1
for i in range(0,len(d)-1):
    if d[i]==d[i+1]:t,m=t+1,max(m,t+1)
    else:m,t=max(m,t),1      
print(m)
