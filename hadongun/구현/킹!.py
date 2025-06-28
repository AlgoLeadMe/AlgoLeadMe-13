import sys
input = sys.stdin.readline

king, stone, N = input().split()
N = int(N)

# 킹과 돌의 초기 좌표를 문자 → 숫자로 변환
letter_king = ord(king[0])
number_king = int(king[1:])
letter_stone = ord(stone[0])
number_stone = int(stone[1:])

# 방향 정의
moves =
{
    'R': (1, 0),
    'L': (-1, 0),
    'B': (0, -1),
    'T': (0, 1),
    'RT': (1, 1),
    'LT': (-1, 1),
    'RB': (1, -1),
    'LB': (-1, -1)
}


def is_valid(x, y):
    return ord('A') <= x <= ord('H') and 1 <= y <= 8

for _ in range(N):
    move = input().strip()
    if move not in moves:
        continue

    dx, dy = moves[move]

    
    next_king_x = letter_king + dx
    next_king_y = number_king + dy

   
    if not is_valid(next_king_x, next_king_y):
        continue

    
    if next_king_x == letter_stone and next_king_y == number_stone:
        next_stone_x = letter_stone + dx
        next_stone_y = number_stone + dy

       
        if not is_valid(next_stone_x, next_stone_y):
            continue

        
        letter_stone = next_stone_x
        number_stone = next_stone_y

   
    letter_king = next_king_x
    number_king = next_king_y


print(chr(letter_king) + str(number_king))
print(chr(letter_stone) + str(number_stone))





''''import sys
input = sys.stdin.readline
king, stone, N = input().split()
N = int(N)
letter_king = ord(king[0])
number_king = int(king[1:])
letter_stone = ord(stone[0])
number_stone = int(stone[1:])
#ord('A') = 65
for i in range(N):
    move = input().strip()
    if move == 'R':
        if letter_stone == letter_king + 1:
            if letter_stone + 1 < 73 and letter_king + 1 < 73:
                letter_king += 1
                letter_stone += 1
            else:
                continue
        else:
            if letter_king + 1 < 73:
                letter_king += 1
            else:
                continue
                
    elif move == 'L':
        if letter_stone == letter_king - 1:
            if letter_stone - 1 > 64 and letter_king -1 > 64:
                letter_king -= 1
                letter_stone -= 1
            else:
                continue
        else:
            if letter_king - 1 > 64:
                letter_king -= 1
            else:
                continue
            
    elif move == 'B':
        if number_stone == number_king - 1:
            if number_stone - 1 > 0 and number_king -1 > 0:
                number_king -= 1
                number_stone -= 1
            else:
                continue
        else:
            if number_king - 1 > 0:
                number_king -= 1
            else:
                continue
            
    elif move == 'T':
        if number_stone == number_king + 1:
            if number_stone + 1 < 9 and number_king + 1 < 9:
                number_king += 1
                number_stone += 1
            else:
                continue
        else:
            if number_king + 1 < 9:
                number_king += 1
            else:
                continue
            
    elif move == 'RT':
        if number_stone == number_king + 1 and letter_stone == letter_king + 1:
            if number_stone + 1 < 9 and letter_stone + 1 < 73:
                number_stone += 1
                number_king += 1
                letter_stone += 1
                letter_king += 1
            else:
                continue
        else:
            if number_king + 1 < 9 and letter_king + 1 < 73:
                number_king += 1
                letter_king += 1
            else:
                continue
            
    elif move == 'LT':
        if number_stone == number_king + 1 and letter_stone == letter_king - 1:
            if number_stone + 1 < 9 and letter_stone -1 > 64:
                number_stone += 1
                number_king += 1
                letter_stone -= 1
                letter_king -= 1
            else:
                continue
        else:
            if number_king + 1 < 9 and letter_king - 1 > 64:
                number_king += 1
                letter_king -= 1
            else:
                continue
            
    elif move == 'RB':
        if number_stone == number_king - 1 and letter_stone == letter_king + 1:
            if number_stone - 1 > 0 and letter_stone + 1 < 73:
                number_stone -= 1
                number_king -= 1
                letter_stone += 1
                letter_king += 1
            else:
                continue
        else:
            if number_king - 1 > 0 and letter_king + 1 < 73:
                number_king -= 1
                letter_king += 1
            else:
                continue
            
    elif move == 'LB':
        if number_stone == number_king - 1 and letter_stone == letter_king - 1:
            if number_stone - 1 > 0 and letter_stone - 1 > 64:
                number_stone -= 1
                number_king -= 1
                letter_stone -= 1
                letter_king -= 1
            else:
                continue
        else:
            if number_king - 1 > 0 and letter_king - 1 > 64:
                number_king -= 1
                letter_king -= 1
            else:
                continue
    else:
        continue
print(chr(letter_king), end='')
print(number_king)
print(chr(letter_stone), end='')
print(number_stone)
''''
    
