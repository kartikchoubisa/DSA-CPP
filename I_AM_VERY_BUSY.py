from pprint import PrettyPrinter
# quicksort
def partition(arr,start,end):
    print("---entered partition")
    pivot = arr[end]
    pIndex=start
    pp = PrettyPrinter()
    pp.pprint(f'{arr=}, {start=}, {end=}, {pivot=}, subarray={arr[start:end+1]}')
    for i,e in enumerate(arr[start:end],start=start):
        if e<=pivot:
            arr[i], arr[pIndex] = arr[pIndex], arr[i]
            print(f'arr[{i}] <-> arr[{pIndex}]')
            pIndex+=1
    arr[pIndex], arr[end] = pivot, arr[pIndex]
    pp.pprint(f'finally {arr=}')
    print(f"---exitted partition {pIndex=}")
    return pIndex


def quicksort(arr, start, end):
    print("---entered quicksort")
    #basecase:
    if start>=end:
        return
        
    #recursive:
    pIndex = partition(arr,start,end)
    quicksort(arr, start, pIndex-1)
    quicksort(arr, pIndex+1, end)
    print("---exitted quicksort")

myarr = [7,1,6,3,2]
quicksort(myarr, 0, len(myarr)-1)
print(myarr)