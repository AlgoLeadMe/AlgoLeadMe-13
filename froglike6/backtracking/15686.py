import sys
from itertools import combinations
input = sys.stdin.readline

N, M = map(int, input().split())
houses = []
chickens = []
for r in range(N):
    row = list(map(int, input().split()))
    for i, v in enumerate(row):
        if v == 1:
            houses.append((r, i))
        elif v == 2:
            chickens.append((r, i)) 

min_city_dist = float('inf')
for comb in combinations(chickens, M):
    city_dist = 0
    for hr, hc in houses:
        dist = min(abs(hr-cr) + abs(hc-cc) for cr, cc in comb)
        city_dist += dist
        if city_dist >= min_city_dist:
            break
    min_city_dist = min(min_city_dist, city_dist)
    
print(min_city_dist)