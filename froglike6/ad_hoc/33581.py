import sys
input = sys.stdin.readline

n,k = map(int,input().split())

if n==k:
    print(*range(k, 0, -1))
elif k==n-1:
    if n<5:
        print(-1)
    else:
        print(1, *range(n-1, 1, -1), n)
else:
    print(k, *range(1, k), k+1, *range(k+3, n+1), k+2)