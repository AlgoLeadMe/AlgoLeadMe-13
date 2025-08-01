import sys
input = sys.stdin.readline

n = int(input())
algo = []
for _ in range(n):
    name, d = input().split()
    algo.append((name, int(d)))

m = int(input())
member = {}
for _ in range(m):
    name, tier = input().split()
    tier = int(tier)
    pref = sorted(algo, key=lambda x: (abs(x[1] - tier), x[0]))
    best1, best2 = pref[0][0], pref[1][0]
    member[name] = (best1, best2)

q = int(input())
cur = None

for _ in range(q):
    line = input().strip()
    if line.endswith("- chan!"):
        cur = line.split(" - ")[0]
        print("hai!")
    else:
        best1, best2 = member[cur]
        print(f"{best2} yori mo {best1}")