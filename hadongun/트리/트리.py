import sys
input = sys.stdin.readline

def delete_children(node):
    j = 0
    for ch in graph:
        if ch == node and not is_delete[j]:
            is_delete[j] = True
            delete_children(j)
        j += 1

n = int(input())
is_delete = [False]*n
graph  = [0]*n  
tree = list(map(int, input().split()))
i = 0
for ch in tree:
    graph[i] = ch
    i += 1

number = int(input())
is_delete[number] = True
delete_children(number)

stack = []
u = 0
for ch in graph:
    if not is_delete[u]:
        has_child = False
        j = 0
        for chh in graph:
            if chh == u and not is_delete[j]:
                has_child = True
                break
            j += 1
        if not has_child:
            stack.append(u)
    u += 1

print(len(stack))


        
