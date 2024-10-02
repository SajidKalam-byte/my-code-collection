def Fact(n):
    fact=1
    for i in range(1,n+1):
        fact=fact*i
        print(i)
    return(fact)
num=int(input("Enter an number"))
print(Fact(num))