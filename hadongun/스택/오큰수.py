import sys
N = int(input())
Numlist = []
Numlist = list(map(int, input().split()))
reverse = Numlist[::-1]
if N==1:
    print(-1)
    sys.exit()
while len(reverse):
    check = True
    currunt = reverse.pop()
        
    for i in range(len(reverse), 0, -1):
        if reverse[i-1] > currunt:
            Max = reverse[i-1]
            check = False
            break
    if check:
        print(-1, end=' ')
        continue
        
    print(Max, end=' ')
    
    if len(reverse) == 1:
        print(-1)
        sys.exit()    


