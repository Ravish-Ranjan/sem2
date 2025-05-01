def can(candies,k):
    def heapify(arr,size,i):
        l = 2*i+1
        r = 2*i+2
        larg = i
        if (l<size and arr[l] < arr[larg]):
            larg = l
        if (r<size and arr[r] < arr[larg]):
            larg = r

        if (larg != i):
            arr[i],arr[larg] = arr[larg],arr[i]
            heapify(arr,size,larg)

    n = len(candies)
    for i in range(n//2 - 1, -1,-1):
        heapify(candies,n,i)
    for i in range(n-1,0,-1):
        candies[0],candies[i]=candies[i],candies[0]
        heapify(candies,i,0)
    print(candies)

can([1,3,4,2,5],10)        
      

