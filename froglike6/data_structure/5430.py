from collections import deque
import sys
input = sys.stdin.readline

for _ in range(int(input())):
    func = input().rstrip()
    if int(input()) == 0:
        arr = deque()
        input()
    else:
        arr = deque(map(int, input()[1:-2].split(",")))
    rev = False
    err = False
    for i in func:
        if i == "R":
            rev = not rev
        else:
            if not arr:
                print("error")
                err = True
                break
            elif rev:
                arr.pop()
            else:
                arr.popleft()
        
    if not err:
        if rev:
            arr.reverse()
        print(f"[{','.join(map(str, arr))}]")