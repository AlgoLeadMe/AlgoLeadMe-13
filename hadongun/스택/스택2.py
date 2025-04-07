import sys

def stack_boy():
    stack = []
    
    input_data = sys.stdin.read().splitlines()
    N = int(input_data[0])

    for i in range(1, N + 1):
        command = input_data[i].split()
        cmd = command[0]

        if cmd == "1":
            stack.append(int(command[1]))

        elif cmd == "2":
            print(stack.pop() if stack else -1)

        elif cmd == "3":
            print(len(stack))

        elif cmd == "4":
            print(1 if not stack else 0)

        elif cmd == "5":
            print(stack[-1] if stack else -1)

stack_boy()
