from random import random
import time
COUNT=int(0)

def merge(arr, l, m, r):
    n1 = m - l + 1
    n2 = r - m
    L = [0] * (n1)
    R = [0] * (n2)

    for i in range(0, n1):
        L[i] = arr[l + i]

    for j in range(0, n2):
        R[j] = arr[m + 1 + j]

    i = 0	
    j = 0	
    k = l	

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            global COUNT
            COUNT+=1
            arr[k] = L[i]
            i += 1
        else:
            COUNT+=1
            arr[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

def mergeSort(arr, l, r):
	if l < r:
		m = l+(r-l)//2
		mergeSort(arr, l, m)
		mergeSort(arr, m+1, r)
		merge(arr, l, m, r)

arr=[]

for size in [10,50,100,500,1000,5000,10000,50000,100000,500000,1000000]:
    print('[*]Sorting With X')
    begin=time.time()
    print('[*]Genrating array of SIZE=',size,'...')

    for j in range(size):
        arr.append([round(random()*size),round(random()*size)])

    print('[+]Array: ',end='')
    print(arr[0],arr[1],'...',arr[size-2],arr[size-1])

    print('[*]Sorting...')
    mergeSort(arr, 0, size-1)
    print('[+]Sorted array: ',end='')
    print(arr[0],arr[1],'...',arr[size-2],arr[size-1])

    end=time.time()

    print('[!]Execution time: ',(end-begin)*1000)
    print('[!]Comprision count: ',COUNT)
    arr=[]
    print('----')
    print('[*]Sorting With Y')
    begin=time.time()

    print('[*]Genrating array...')
    for j in range(size):
        arr.append([round(random()*size),round(random()*size)])

    print('[+]Array: ',end='')
    print(arr[0],arr[1],'...',arr[size-2],arr[size-1])

    print('[*]Sorting...')
    for i in range(size):
        arr[i]=[arr[i][1],arr[i][0]]
    mergeSort(arr, 0, size-1)
    for i in range(size):
        arr[i]=[arr[i][1],arr[i][0]]
    print('[+]Sorted array: ',end='')
    print(arr[0],arr[1],'...',arr[size-2],arr[size-1])

    end=time.time()

    print('[!]Execution time: ',(end-begin)*1000)
    print('[!]Comprision count: ',COUNT)
    arr=[]
    print('--------------------------------------------------------')