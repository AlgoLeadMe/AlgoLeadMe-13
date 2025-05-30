import sys
input = sys.stdin.readline

def bfs(root, n, graph):
    parent = [0]*n
    visited = [False]*n
    stack = []
    
    visited[root-1] = True
    
    for neighbor in graph[root]:
        stack.append(neighbor)
        parent[neighbor-1] = root
        visited[neighbor-1] = True
        
    while stack:
        temp = stack.pop()
        for neighbor in graph[temp]:
            if not visited[neighbor-1]:
                parent[neighbor-1] = temp
                visited[neighbor-1] = True
                stack.append(neighbor)
    return parent
n = int(input())

graph = [[] for _ in range(n+1)]

for _ in range(n-1):
    a,b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
root = 1
result = bfs(root, n, graph)
count = 0
for i in result:
    if count == 0:
        count += 1
        continue
    else:
        print(i)
    count += 1
    
    
    


