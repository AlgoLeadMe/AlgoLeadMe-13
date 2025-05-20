'''
       [0]
      w w w
      w w w
      w w w 
 [4]   [2]   [5]   [3]
g g g r r r b b b o o o
g g g r r r b b b o o o
g g g r r r b b b o o o
       [1]
      y y y
      y y y
      y y y

'''
import sys
input = sys.stdin.readline
cube=[[["w","w","w"],["w","w","w"],["w","w","w"]],
 [["y","y","y"],["y","y","y"],["y","y","y"]],
 [["r","r","r"],["r","r","r"],["r","r","r"]],
 [["o","o","o"],["o","o","o"],["o","o","o"]],
 [["g","g","g"],["g","g","g"],["g","g","g"]],
 [["b","b","b"],["b","b","b"],["b","b","b"]]]

def clear():
    return [[["w","w","w"],["w","w","w"],["w","w","w"]],
 [["y","y","y"],["y","y","y"],["y","y","y"]],
 [["r","r","r"],["r","r","r"],["r","r","r"]],
 [["o","o","o"],["o","o","o"],["o","o","o"]],
 [["g","g","g"],["g","g","g"],["g","g","g"]],
 [["b","b","b"],["b","b","b"],["b","b","b"]]]

def turn(side):
    if side=="U":
        temp=zip(*cube[0][::-1])
        cube[0]= [list(elem) for elem in temp]
        temp=cube[2][0]
        cube[2][0]=cube[5][0]
        cube[5][0]=cube[3][0]
        cube[3][0]=cube[4][0]
        cube[4][0]=temp
    elif side=="D":
        temp=zip(*cube[1][::-1])
        cube[1]= [list(elem) for elem in temp]
        temp=cube[2][2]
        cube[2][2]=cube[4][2]
        cube[4][2]=cube[3][2]
        cube[3][2]=cube[5][2]
        cube[5][2]=temp
    elif side=="F":
        temp=zip(*cube[2][::-1])
        cube[2]= [list(elem) for elem in temp]
        temp=[cube[0][2][0],cube[0][2][1],cube[0][2][2]]
        cube[0][2][0]=cube[4][2][2]
        cube[0][2][1]=cube[4][1][2]
        cube[0][2][2]=cube[4][0][2]
        cube[4][0][2]=cube[1][0][0]
        cube[4][1][2]=cube[1][0][1]
        cube[4][2][2]=cube[1][0][2]
        cube[1][0][0]=cube[5][2][0]
        cube[1][0][1]=cube[5][1][0]
        cube[1][0][2]=cube[5][0][0]
        cube[5][0][0]=temp[0]
        cube[5][1][0]=temp[1]
        cube[5][2][0]=temp[2]
    elif side=="B":
        temp=zip(*cube[3][::-1])
        cube[3]= [list(elem) for elem in temp]
        temp=cube[0][0]
        cube[0][0]=[cube[5][0][2], cube[5][1][2], cube[5][2][2]]
        cube[5][0][2]=cube[1][2][2]
        cube[5][1][2]=cube[1][2][1]
        cube[5][2][2]=cube[1][2][0]
        cube[1][2][2]=cube[4][2][0]
        cube[1][2][1]=cube[4][1][0]
        cube[1][2][0]=cube[4][0][0]
        cube[4][2][0]=temp[0]
        cube[4][1][0]=temp[1]
        cube[4][0][0]=temp[2]
    elif side=="L":
        temp=zip(*cube[4][::-1])
        cube[4]= [list(elem) for elem in temp]
        temp=[cube[0][0][0], cube[0][1][0], cube[0][2][0]]
        cube[0][0][0]=cube[3][2][2]
        cube[0][1][0]=cube[3][1][2]
        cube[0][2][0]=cube[3][0][2]
        cube[3][2][2]=cube[1][0][0]
        cube[3][1][2]=cube[1][1][0]
        cube[3][0][2]=cube[1][2][0]
        cube[1][0][0]=cube[2][0][0]
        cube[1][1][0]=cube[2][1][0]
        cube[1][2][0]=cube[2][2][0]
        cube[2][0][0]=temp[0]
        cube[2][1][0]=temp[1]
        cube[2][2][0]=temp[2]
    elif side=="R":
        temp=zip(*cube[5][::-1])
        cube[5]= [list(elem) for elem in temp]
        temp=[cube[0][0][2], cube[0][1][2], cube[0][2][2]]
        cube[0][0][2]=cube[2][0][2]
        cube[0][1][2]=cube[2][1][2]
        cube[0][2][2]=cube[2][2][2]
        cube[2][0][2]=cube[1][0][2]
        cube[2][1][2]=cube[1][1][2]
        cube[2][2][2]=cube[1][2][2]
        cube[1][0][2]=cube[3][2][0]
        cube[1][1][2]=cube[3][1][0]
        cube[1][2][2]=cube[3][0][0]
        cube[3][2][0]=temp[0]
        cube[3][1][0]=temp[1]
        cube[3][0][0]=temp[2]

for _ in range(int(input())):
    m = input()
    a = input().split()
    for i in range(int(m)):
        p, q = list(a[i])
        if q=="+":
            turn(p)
        elif q=="-":
            turn(p)
            turn(p)
            turn(p)
    for k in range(3):
        for l in range(3):
            print(cube[0][k][l], end='')
        print()
    cube=clear()