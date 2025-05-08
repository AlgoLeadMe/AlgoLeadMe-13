import math
import sys
input = sys.stdin.readline

def main():
    xA, yA, xB, yB, xC, yC = map(int, input().split())

    cross = (xB - xA) * (yC - yA) - (yB - yA) * (xC - xA)
    if cross == 0:
        print(-1)
        return

    dAB = math.hypot(xA - xB, yA - yB)
    dBC = math.hypot(xB - xC, yB - yC)
    dCA = math.hypot(xC - xA, yC - yA)

    s1 = dAB + dCA
    s2 = dAB + dBC
    s3 = dBC + dCA 

    answer = 2 * (max(s1, s2, s3) - min(s1, s2, s3))

    print(f"{answer:.15f}")

if __name__=="__main__":
    main()