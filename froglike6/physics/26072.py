import sys
input = sys.stdin.readline
N, L = map(int, input().split())
x_list = list(map(int, input().split()))
w_list = list(map(int, input().split()))

total_weight = sum(w_list)
weighted_sum = sum(w * x for x, w in zip(x_list, w_list))

pivot = weighted_sum / total_weight

print(f"{pivot:.10f}")