import sys
N = int(input())
su = []
for _ in range(N):
    su.append(int(sys.stdin.readline()))
su.sort()
length = len(su)

#산술평균
average = 0
for i in range(length):
    average += su[i]
print(average//length)

#중앙값
print(su[(length//2)])
#최빈값
count = [0]*8001
for ch in su:
    count[ch + 4000] += 1
Max = count[0]
temp = 0
max_list = []
Max = max(count)
for k in range(len(count)):
    if count == Max:
        max_list.append(k-4000)
if len(max_list) > 1:
    print(max_list[1])
else:
    print(max_list[0])
    
print(temp-4000)

#범위
print(su[length-1] - su[0])

""""
#최빈값 실패 
yang = [0]*500001
emm = [0]*500001
for i in range(length):
    if su[i] >= 0:
        yang[su[i]] += 1
    else:
        emm[abs(su[i])] += 1
Max = 0
count = 0
dex = 0

for j in range(500001):
    if Max < yang[j]:
        Max = yang[j]
        dex = j
    elif Max < emm[j]:
        Max = emm[j]
        dex = -j
    elif Max == emm[j]:
        count += 1
        if count == 2:
            dex = -j
            Max = emm[j]
            
    elif Max == yang[j]:
        count += 1
        if count == 2:
            dex = j
            Max = yang[j]

print(dex)
""""

    
        
        
        



    
