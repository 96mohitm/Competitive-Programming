import numpy as np
import pandas as pd

t = int(input())

while t > 0:
    t = t-1
    n,m,k = list(map(int, input().split()))
    l = list()
    for i in range(k):
        tl = list(map(int, input().split()))
        l.append(tl)

    df = pd.DataFrame(l)
    a = np.array(l)
    a = a[np.lexsort((a[:,1],a[:,0]))]
    c = 0
    for i in range(1, k):
        print(a[i, 0], ' ', a[i, 1])
        if a[i - 1, 0] == a[i, 0] and a[i - 1, 1] == a[i, 1] - 1:
            c += 1
    a = a[np.lexsort((a[:,0], a[:,1]))]
    for i in range(1,k):
        if a[i - 1, 1] == a[i, 1] and a[i - 1, 0] == a[i, 0] - 1:
            c += 1
    r = k*4 - 2*c
    print(r)
