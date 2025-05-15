import sys
input = sys.stdin.readline

n, b = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(n)]

def multMat(A, B):
    C = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            s = 0
            for k in range(n):
                s += A[i][k] * B[k][j]
            C[i][j] = s % 1000
    return C

def powMat(A, exp):
    result = [[1 if i == j else 0 for j in range(n)] for i in range(n)]
    base = [row[:] for row in A]
    while exp > 0:
        if exp % 2 == 1:
            result = multMat(result, base)
        base = multMat(base, base)
        exp //= 2
    return result

ans = powMat(matrix, b)

for row in ans:
    print(*row)