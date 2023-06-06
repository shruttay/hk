from SetOperations import Set

def create():
    n = int(input("\nEnter the number of elements : "))
    s = Set(n)
    return s

s1 = create()
print("\nSet A : ")
print(str(s1))

while(True):
    print("\n******MENU******")
    print("1 : Add")
    print("2 : Remove")
    print("3 : Contains")
    print("4 : Size")
    print("5 : Intesection")
    print("6 : Union")
    print("7 : Difference")
    print("8 : Subset")
    print("9 : Exit")
    ch = int(input("\nEnter your Choice : "))
    if(ch == 9):
        print("\nEnd of Program")
        break
    elif(ch == 1):
        e = int(input("\nEnter Element to add : "))
        s1.add(e)
        print(str(s1))
    elif(ch == 2):
        e = int(input("\nEnter Element to remove : "))
        s1.remove(e)
        print(str(s1))
    elif(ch == 3):
        e = int(input("\nEnter Element to search : "))
        if e in s1:
            print("Element is Present")
        else:
            print("Element is not Present")
    elif(ch == 4):
        print("\nSize of set is : ",len(s1))
    elif(ch == 5):
        s2 = create()
        s3 = s1.intersection(s2)
        print("\nSet A : ",str(s1))
        print("Set B : ",str(s2))
        print("Set C : ",str(s3))
    elif(ch == 6):
        s2 = create()
        s3 = s1.union(s2)
        print("\nSet A : ",str(s1))
        print("Set B : ",str(s2))
        print("Set C : ",str(s3))
    elif(ch == 7):
        s2 = create()
        s3 = s1.difference(s2)
        print("\nSet A : ",str(s1))
        print("Set B : ",str(s2))
        print("Set C : ",str(s3))
    elif(ch == 8):
        s2 = create()
        print("\nSet A : ",str(s1))
        print("Set B : ",str(s2))
        isSubset = s1.subset(s2)
        if isSubset:
            print("Set B is Subset of Set A")
        else:
            print("Set B is not Subset of Set A")
    else:
        print("\nIncorrect Input")
