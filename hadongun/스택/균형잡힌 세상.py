import sys
while True:
    charrr = sys.stdin.readline().rstrip()
    if charrr == ".":
        break
    are_you_balanced = True
    stack = []
    for ch in charrr:
        if ch == "(" or ch == "[":
            stack.append(ch)
        elif ch == ")":
            if stack and stack[-1] == "(":
                stack.pop()
            else:
                are_you_balanced = False
                break
        elif ch == "]":
            if stack and stack[-1] == "[":
                stack.pop()
            else:
                are_you_balanced = False
                break
    if are_you_balanced and not stack:
        print("yes")
    else:
        print("no")

'''import sys
stack = []
roundbalance = 0
anglebalance = 0
while True:
    charrr = sys.stdin.readline().strip()
    for ch in charrr:
        stack.append(ch)
    if charrr == "":
        break
    while stack:
        if stack[-1] == "(":
            roundbalance += 1
            stack.pop()
        elif stack[-1] == ")":
            roundbalance -= 1
            stack.pop()
        elif stack[-1] == "[":
            anglebalance += 1
            stack.pop()
        elif stack[-1] == "]":
            anglebalance -= 1
            stack.pop()
        else:
            stack.pop()
        if len(stack) == 0:
            break
    if roundbalance == 0 and anglebalance == 0:
        print("yes")
    else:
        print("no")'''
        
        
            
        
    

