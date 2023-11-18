import math
import sys

# 점점 작아지시고
def right(k):
    return 1200 / math.sqrt(k)

def denom(k):
    ret = 0
    for i in range(1, k+1):
        ret += (0.9) ** (k-1)
    return ret

for i in range(1, 100):
    print(denom(i))