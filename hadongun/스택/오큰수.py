def okensu(n, array):
    stack = []
    result = [-1]*n
    for i in range(n-1, -1, -1):
        while stack and stack[-1] <= array[i]:
            stack.pop()
            
        if stack:
            result[i] = stack[-1]

                
        stack.append(array[i])
        
    print(*result)   

N = int(input())
List = list(map(int, input().split()))
okensu(N, List)
