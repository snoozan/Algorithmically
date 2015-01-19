"""
@author: Susan Lunn
January 19th, 2015
"""



def split(arr):
    if(len(arr) < 2): #means can't be split anymore
        return arr
    middle = len(arr)//2 #index of split
    left = split(arr[:middle]) #split the left half
    right = split(arr[middle:]) #split the right half

    return merge(left, right) #merge it, mofo


def merge(left, right):
    pt_left = 0
    pt_right = 0

    temp = []
    length = len(left) + len(right)

    while len(temp) < length:
        if(pt_left >= len(left)): #if the left pointer goes beyond bounds of left
            temp.append(right[len(right)-1])
        elif(pt_right >= len(right)): #if the right pointer goes beyond bounds of left
            temp.append(left[len(left) -1])
        else:
            if(left[pt_left] < right[pt_right]): #actual sorting bits
                temp.append(left[pt_left]) #left is less than right, add left to array
                pt_left += 1
            else:
                temp.append(right[pt_right]) #right is less than left, add to array
                pt_right += 1

    return temp #return merged array

arr = [6,5,3,8,1,7,4,2]
print("The unsorted list is: " + str(arr) + "\n")
print("The sorted list is: " +str(split(arr)) + "\n")
