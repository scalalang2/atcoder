import sys
import math
input = sys.stdin.readline

ans = 0
N = int(input())
S = input().rstrip()
target = int("".join(sorted(S)))

for i in range(0, 4000000):
    num = i * i
    if num > 10 ** len(S):
        break
    t = int("".join(sorted(str(num))))
    if target == t:
        ans += 1

print(ans)