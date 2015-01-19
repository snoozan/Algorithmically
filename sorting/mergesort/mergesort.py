arr = [6,5,3,8,1,7,4,2]




def split(arr):
    if(len(arr) < 2):
        return arr
    middle = len(arr)//2
    left = split(arr[:middle])
    right = split(arr[middle:])

    return merge(left, right)


def merge(left, right):
    pt_left = 0
    pt_right = 0

    temp = []
    length = len(left) + len(right)

    while len(temp) < length:
        print("the pt_left is: " + str(pt_left) + " with len being " + str(len(left)) + "\n" + "the pt_right is: " + str(pt_right)+ " with len being " + str(len(right)) + "\n")
        if(left[pt_left] < right[pt_right]):
            if(pt_left < len(left)):
                temp.append(left[pt_right])
                pt_left += 1
            else:
                temp.append(right[len(right)-1])

        else:
            if(pt_right < len(right)):
                temp.append(right[pt_right])
                pt_right += 1
            else:
                temp.append(left[len(left) -1])

    return temp

print split(arr)



