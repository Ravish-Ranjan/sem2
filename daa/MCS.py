import math

def max_crossing_subarray(arr,l,m,h):
    left_sum = -math.inf
    suma = 0
    max_left = m
    for i in range(m,l-1,-1):
        print("left side : ",arr[i])
        suma += arr[i]
        if suma > left_sum:
            left_sum = suma
            max_left = i

    right_sum = -math.inf
    suma = 0
    max_right = m+1
    for i in range(m+1,h+1):
        print("right side : ",arr[i])
        suma += arr[i]
        if suma > right_sum:
            right_sum = suma
            max_right = i
    return (max_left,max_right,left_sum+right_sum)

print("Max cs : ",max_crossing_subarray([10,9,8,7,6,5,4,3,2,1],0,4,9))
