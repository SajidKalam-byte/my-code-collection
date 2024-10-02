t=(50,50,50,50,50,50)
t1=("hello","hello")
x=t1[0]
flag=0
for i in range(0,len(t1)):
    if x!=t1[i]:
        flag=0
        break
    else:
        flag=1
if flag==1:
    print("True")
else:
    print("False")
    
