import sys
stack = []
k = int(input())
for i in range(k):
    N = int(sys.stdin.readline())
    if N != 0:
        stack.append(N)
    else:
        if stack:
            stack.pop()
Sum = 0
temp = 0
while stack:
    temp = stack.pop()
    Sum = Sum + temp
print(Sum)
