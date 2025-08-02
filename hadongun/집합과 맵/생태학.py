import sys
input = sys.stdin.readline

tree = {}
count = 0

while True:
    name = input().strip()
    if name == '':
        break
    count += 1
    if name in tree:
        tree[name] += 1
    else:
        tree[name] = 1

for name in tree:
    tree[name] = round(tree[name] / count * 100, 4)

for name in sorted(tree):
    print(f"{name} {tree[name]:.4f}")
