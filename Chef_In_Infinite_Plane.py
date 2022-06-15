from collections import Counter

T = input()
T = int(T)
for _ in range(T):
    total = 0
    N = int(input())
    nums_counter = Counter(int(x) for x in input().split())
    for key in nums_counter:
        total += min(nums_counter[key], key-1)
    print(total)
    
