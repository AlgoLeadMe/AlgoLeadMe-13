import sys
from collections import deque

def selflocation(campus, n, m):
    result = (0,0)
    for i in range(n):
        for j in range(m):
            if campus[i][j] =='I':
                result = (i,j)
    return result
    

def exploration(campus, n, m, s):
    visited = [[False]*m for _ in range(n)]
    directions = ((1, 0), (-1, 0), (0, 1), (0, -1))
    q = deque()
    q.append(s)
    result = 0
    while q:
        y, x = q.popleft()
        visited[y][x] = True
        for dx, dy in directions:
            ny, nx = y + dy, x + dx

            if 0 <= ny <= n-1 and 0 <= nx <= m-1:
                if campus[ny][nx] != 'X' and not visited[ny][nx]:
                    visited[ny][nx] = True
                    q.append((ny, nx))
                    if campus[ny][nx] == 'P':
                        result += 1
    return result
                
input = sys.stdin.readline
n, m = map(int, input().split())

campus = [['']*m for _ in range(n)]
for i in range(n):
    campus[i] = list(input().strip())
start = selflocation(campus, n, m)
friend = exploration(campus, n, m, start)
if friend == 0:
    print('TT')
else:
    print(friend)
