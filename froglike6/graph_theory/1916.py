import sys
import heapq

def dijkstra(n, graph, start):
    INF = float('inf')
    distances = [INF] * (n + 1)
    distances[start] = 0
    queue = [(0, start)]
    
    while queue:
        current_cost, current_node = heapq.heappop(queue)
        if current_cost > distances[current_node]:
            continue
        for next_node, weight in graph[current_node]:
            cost = current_cost + weight
            if cost < distances[next_node]:
                distances[next_node] = cost
                heapq.heappush(queue, (cost, next_node))
    return distances

input = sys.stdin.readline
N = int(input())
M = int(input())
graph = [[] for _ in range(N+1)]
for _ in range(M):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))
start, end = map(int, input().split())
distances = dijkstra(N, graph, start)
print(distances[end])