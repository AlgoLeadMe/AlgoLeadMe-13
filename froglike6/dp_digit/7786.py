import sys
input = sys.stdin.readline

def f(n):
    total = 0
    p = 1
    while p <= n:
        high = n // (p * 10)
        cur  = (n // p) % 10
        low  = n % p

        total += high * 45 * p
        total += (cur * (cur - 1) // 2) * p
        total += cur * (low + 1)

        p *= 10
    return total

l, u = map(int, input().split())
print(f(u)-f(l-1))