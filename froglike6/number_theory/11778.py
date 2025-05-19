import sys
input = sys.stdin.readline

def gcd(x, y):
    while y:
        x, y = y, x % y
    return x

def fibonacci(n):
    mat = [[1, 1], [1, 0]]
    vec = [1, 0]
    
    while n > 0:
        if n & 1:
            temp = (mat[0][0] * vec[0] + mat[0][1] * vec[1]) % 1000000007
            vec[1] = (mat[1][0] * vec[0] + mat[1][1] * vec[1]) % 1000000007
            vec[0] = temp
        
        mat00 = (mat[0][0] * mat[0][0] + mat[0][1] * mat[1][0]) % 1000000007
        mat01 = (mat[0][0] * mat[0][1] + mat[0][1] * mat[1][1]) % 1000000007
        mat10 = (mat[1][0] * mat[0][0] + mat[1][1] * mat[1][0]) % 1000000007
        mat11 = (mat[1][0] * mat[0][1] + mat[1][1] * mat[1][1]) % 1000000007
        mat[0][0], mat[0][1] = mat00, mat01
        mat[1][0], mat[1][1] = mat10, mat11
        
        n >>= 1
    
    return vec[1]
    
n, m = map(int,input().split())
print(fibonacci(gcd(n,m))%1000000007)
