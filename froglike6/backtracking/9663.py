def dfs(row, cols, diag1, diag2):
    global count
    if row == n:
        count += 1
        return
    available_positions = (~(cols | diag1 | diag2)) & ((1 << n) - 1)
    while available_positions:
        position = available_positions & -available_positions
        available_positions &= available_positions - 1
        dfs(row + 1,
            cols | position,
            (diag1 | position) << 1,
            (diag2 | position) >> 1)
n = int(input())
count = 0
dfs(0, 0, 0, 0)
print(count)