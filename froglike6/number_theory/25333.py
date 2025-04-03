import sys
input = sys.stdin.readline
def gcd(x, y):
    while y:
        x, y = y, x % y
    return x
for _ in range(int(input())):
    a,b,x=map(int,input().split())
    print(x//gcd(a,b))