import sys
input = sys.stdin.readline

for _ in range(int(input())):
    ps = input().rstrip()
    stack = 0
    for i in range(len(ps)):
        if stack < 0:
            break
        else:
            if ps[i]=="(":
                stack+=1
            else:
                stack-=1
    if not stack == 0:
        print("NO")
    else:
        print("YES")



