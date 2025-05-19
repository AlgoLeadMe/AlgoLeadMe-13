n = int(input())
top = list(map(int, input().split()))
result = [0] * n
stack = []

for i in range(n):
    while stack and top[stack[-1]] < top[i]:
        stack.pop()
    if stack:
        result[i] = stack[-1] + 1
    stack.append(i)

print(*result)


''''import sys
n = int(input())
top = list(map(int, input().split()))
result = [0]*n
for i in range(n, 1, -1):
    count = i - 1
    copytop = top[:]
    current = copytop.pop()
    for _ in range(n-1):
        if copytop:
            temp = copytop.pop()
            if temp > current:
                result[i-1] = count
                top.pop()
                break
            else:
                count -= 1
print(result)
''''
    



    
