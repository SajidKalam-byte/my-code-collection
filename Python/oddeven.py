l1=[12,26,84,93,73,55,24,1,12,32,12]
evenL,oddL=[num for num in l1 if num%2==0],[num for num in l1 if num%2!=0]
print("Even Numbers: ", evenL)
print("Odd Numbers: ", oddL)