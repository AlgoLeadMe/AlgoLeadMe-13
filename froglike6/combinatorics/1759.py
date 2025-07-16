from itertools import combinations
import sys
input = sys.stdin.readline

L, C = map(int, input().split())
letters = sorted(input().split())
vowels = {'a', 'e', 'i', 'o', 'u'}

for combo in combinations(letters, L):
    v_cnt = sum(ch in vowels for ch in combo)
    if v_cnt >= 1 and L - v_cnt >= 2:
        print(''.join(combo))