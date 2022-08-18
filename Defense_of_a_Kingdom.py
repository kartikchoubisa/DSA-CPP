import itertools as it

t = int(input())
for _ in range(t):
    x_dim, y_dim, n = input().split()
    x_dim = int(x_dim)
    y_dim = int(y_dim)
    n = int(n)
    if n == 0:
        print(x_dim*y_dim)
        continue
    towers = [tuple(map(lambda x: int(x), input().split())) for _ in range(n)]
    towers.append((0,0))
    towers.append((x_dim+1, y_dim+1))
    
    towers.sort(key = lambda x: x[0])
    x_win = max(map(
        lambda s: s[1]-s[0]-1, 
        it.pairwise((x[0] for x in towers))
        ))

    towers.sort(key = lambda x: x[1])
    y_win = max(map(
        lambda s: s[1]-s[0]-1, 
        it.pairwise((x[1] for x in towers))
        ))
    
    print(y_win*x_win)
    