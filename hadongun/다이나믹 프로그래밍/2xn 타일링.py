import math

n = int(input())
method_num = 0

for i in range(0, n // 2 + 1):  # 세로 블럭의 개수 i (2칸씩 차지)
    method_num += math.comb(n - i, i)  # 총 n - i개 자리 중 i개 세로 위치 선택

print(method_num % 10007)
