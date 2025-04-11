import sys

def sort_word():
    n = int(input())
    unsorted_word = [sys.stdin.readline().strip() for _ in range(n)]
    sorted_wording = set(unsorted_word)
    sorted_word = sorted(sorted_wording, key = lambda x : (len(x), x))
    for word in sorted_word:              
        print(word)
sort_word()


"""
시간 초과가 발생한 코드. 맞는 지는 모르겠습니다.
def sort_word():
    n = int(input())
    unsorted_word = sys.stdin.read().splitlines()
    for i in range(1, n):
        key = len(unsorted_word[i])
        j = i -1

        while j >=0 and key < len(unsorted_word[j]):
            if key == len(unsorted_word[j]):
                if unsorted_word[i] == unsorted_word[j]:
                    del unsorted_word[i]
                if unsorted_word[j] > unsorted_word[i]:
                    temp = unsorted_word[j]
                    unsorted_word[j] = unsorted_word[i]
            unsorted_word[j + 1] = unsorted_word[j]
            unsorted_word[j] = unsorted_word[j]
            j -= 1
            
        
        
        
    print(unsorted_word)
sort_word()"""
                
            
        
    
