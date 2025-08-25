import sys
input = sys.stdin.readline

def gojangnan_clock(h, m, n):
    theta_h = h * 30
    theta_m = m * 6
    delta0 = (theta_m - theta_h) % 360
    t1 = (360 - delta0) / 6
    t = n
    if t <= t1:
        theta_h += 6 * t
        theta_m += 12 * t
        t=0
    else:
        theta_h += 6 * t1
        theta_m += 12 * t1
        t -= t1
        block = t//80
        theta_h += 6 * 80 * block
        theta_m += 120 * block
        t -= 80 * block
        if t <= 20:
            theta_h += 6 * t
            theta_m -= 12 * t
            t=0
        else:
            theta_h += 120
            theta_m -= 240
            t -= 20
            theta_h += 6 * t
            theta_m += 12 * t
            t = 0
    theta_h %= 360
    theta_m %= 360
    return (int(theta_h // 30) % 12, int(theta_m // 6))
h, m = map(int, input().split())
n = int(input())
print(*gojangnan_clock(h,m,n))