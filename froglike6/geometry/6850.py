import sys
input = sys.stdin.readline

def cross(o, a, b):
    return (a[0]-o[0])*(b[1]-o[1])-(a[1]-o[1])*(b[0]-o[0])
    
def convex_hull(points):
    points = sorted(set(points))

    if len(points) <= 1:
        return points

    lower = []
    for p in points:
        while len(lower) >= 2 and cross(lower[-2], lower[-1], p) <= 0:
            lower.pop()
        lower.append(p)

    upper = []
    for p in reversed(points):
        while len(upper) >= 2 and cross(upper[-2], upper[-1], p) <= 0:
            upper.pop()
        upper.append(p)

    return lower[:-1] + upper[:-1]
    
def shoelace_area(polygon):
    n = len(polygon)
    area = 0
    for i in range(n):
        x1, y1 = polygon[i]
        x2, y2 = polygon[(i + 1) % n]
        area += (x1 * y2) - (x2 * y1)
    return abs(area) / 2

input_points = []
for _ in range(int(input())):
    a, b = map(int,input().split())
    input_points.append((a,b))

print(int(shoelace_area(convex_hull(input_points))//50))