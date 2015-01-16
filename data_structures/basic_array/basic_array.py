list = [1, 2, 3, 4]
print (list)
##python using extend to append multiple values to a list, instead of extend
list.extend([5, 6])
##list.append will get [1,2,3,4 [5, 6]]
print (list)
##+= also works, and is less expensive than the function call .extend, use for preformance
list += [6] ##however, you can't just add objects to the list, they must be listified first
print(list)
