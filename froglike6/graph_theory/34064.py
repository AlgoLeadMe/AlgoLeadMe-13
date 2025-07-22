import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())
grid = [[0]*M for _ in range(N)]
for _ in range(K):
    x, y = map(int, input().split())
    grid[x-1][y-1] = 1

a1, b1 = map(int, input().split())
a2, b2 = map(int, input().split())
a3, b3 = map(int, input().split())
a4, b4 = map(int, input().split())

a1, b1, a2, b2 = a1-1, b1-1, a2-1, b2-1
a3, b3, a4, b4 = a3-1, b3-1, a4-1, b4-1

visited = [[False]*M for _ in range(N)]
dirs = [(1,0),(-1,0),(0,1),(0,-1)]
answer = 0

for i in range(N):
    for j in range(M):
        if grid[i][j] == 0 and not visited[i][j]:
            stack = [(i, j)]
            visited[i][j] = True
            countA = 0
            countB = 0
            
            while stack:
                x, y = stack.pop()
                if a1 <= x <= a2 and b1 <= y <= b2:
                    countA += 1
                if a3 <= x <= a4 and b3 <= y <= b4:
                    countB += 1

                for dx, dy in dirs:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < N and 0 <= ny < M:
                        if grid[nx][ny] == 0 and not visited[nx][ny]:
                            visited[nx][ny] = True
                            stack.append((nx, ny))

            answer += countA * countB

print(answer)