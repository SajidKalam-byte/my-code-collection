from dictionary import *

#printing key and its value
for item in box:
    print(item,box[item])

#now sorting value
newkey=list(box.keys())
newkey.sort()

sorted_dict = {item: box[item] for item in newkey}

print(sorted_dict)


