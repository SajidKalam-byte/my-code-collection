t=(60,70,50,60,50,60)
l=[]
for i in t:
    if t.count(i)>1:
        if i not in l:
            l.append(i)
print(l)
print(t[-2:-5:-1])
