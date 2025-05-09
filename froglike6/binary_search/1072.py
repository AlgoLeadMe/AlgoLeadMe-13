import sys
input=sys.stdin.readline

def solve(X, Y):
    Z = (Y * 100) // X

    if Z >= 99:
        return -1

    left, right = 1, 10**9
    answer = -1

    while left <= right:
        mid = (left + right) // 2
        new_Z = ((Y + mid) * 100) // (X + mid)

        if new_Z > Z:
            answer = mid
            right = mid - 1
        else:
            left = mid + 1

    return answer

X, Y = map(int, input().split())
print(solve(X, Y))