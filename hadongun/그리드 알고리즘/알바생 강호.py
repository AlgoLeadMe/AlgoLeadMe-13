import sys
N = int(input())
tip_temp = map(int ,[sys.stdin.readline().strip() for _ in range(N)])
tip = list(tip_temp)
tip.sort(reverse = True)
receive = 0
for i in range(1, N + 1):
    if tip[i-1] + 1 - i < 0:
        continue
    receive += (tip[i-1] + 1 - i)

print(receive)
            
    
