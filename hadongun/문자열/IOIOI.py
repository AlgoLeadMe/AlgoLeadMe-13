import sys
input = sys.stdin.readline

N = int(input())
s_len = int(input())
s = list(input().strip())

i = 0
count = 0

while i < s_len - (2 * N):
    if s[i] == 'I':
        is_pass = True
        for j in range(N):
            
            if s[i + 2*j + 1] != 'O':
                is_pass = False
                break
            
            if s[i + 2*j + 2] != 'I':
                is_pass = False
                break
        if is_pass:
            count += 1
            i += 2  
        else:
            i += 1
    else:
        i += 1

print(count)
