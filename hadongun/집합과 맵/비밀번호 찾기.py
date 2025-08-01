import sys

n, m = map(int, input().split())

passwords = {}
for _ in range(n):
    site, password = input().split()
    passwords[site] = password

for _ in range(m):
    find = input().strip()
    print(passwords[find])
