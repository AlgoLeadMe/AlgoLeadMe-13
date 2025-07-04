import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
x = int(input())

arr.sort()
start = 0
end = n-1
Sum = 0
count = 0
while start < end:
    Sum = arr[start] + arr[end]
    if Sum == x:
        count += 1
        start += 1
        end -= 1
        
    elif Sum < x:
        start += 1
        
    else:
        end -= 1
print(count)

        
        
