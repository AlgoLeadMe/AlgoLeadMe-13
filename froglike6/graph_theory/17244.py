import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
grid = [input().rstrip() for _ in range(m)]
node, item, start, exit = [], [], None, None

for y in range(m):
    for x in range(n):
        if grid[y][x] == "S":
            start = (y, x)
        elif grid[y][x] == "E":
            exit = (y, x)
        elif grid[y][x] == "X":
            item.append((y, x))

node = [start]+item+[exit]
k, l = len(item), len(item)+2
dist = [[-1]*l for _ in range(l)]
h,w,dirs=m,n,[(1, 0), (-1, 0), (0, 1), (0, -1)]

for idx, (sy, sx) in enumerate(node):
    d = [[-1] * w for _ in range(h)]
    q = deque([(sy, sx)])
    d[sy][sx] = 0
    while q:
        y, x = q.popleft()
        for dy, dx in dirs:
            ny, nx = y + dy, x + dx
            if 0 <= ny < h and 0 <= nx < w and grid[ny][nx] != '#' and d[ny][nx] == -1:
                d[ny][nx] = d[y][x] + 1
                q.append((ny, nx))
    for j, (ty, tx) in enumerate(node):
        dist[idx][j] = d[ty][tx]
        
if k == 0:
    print(dist[0][1])
else:
    INF = 10 ** 9
    dp = [[INF] * (k + 1) for _ in range(1 << k)]
    dp[0][0] = 0
    for mask in range(1 << k):
        for i in range(k + 1):
            cur = dp[mask][i]
            if cur == INF:
                continue
            for j in range(k):
                if mask & 1 << j:
                    continue
                cost = dist[i][j + 1]
                if cost == -1:
                    continue
                nxt = mask | 1 << j
                if dp[nxt][j + 1] > cur + cost:
                    dp[nxt][j + 1] = cur + cost
    all_mask, ans = (1 << k) - 1, INF
    for i in range(k + 1):
        if dp[all_mask][i] == INF or dist[i][k + 1] == -1:
            continue
        ans = min(ans, dp[all_mask][i] + dist[i][k + 1])
    print(ans)