#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000001

// 연결 리스트 노드 구조체 정의
typedef struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
} Node;

// 리스트의 시작과 끝을 관리하기 위한 구조체
typedef struct {
    Node* head;
    Node* tail;
} List;

// 리스트 초기화
void init_list(List* list) {
    list->head = NULL;
    list->tail = NULL;
}

// 새 노드 삽입 (커서 바로 앞 위치)
void insert(List* list, Node** cursor, char ch) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = ch;
    new_node->prev = NULL;
    new_node->next = NULL;

    // 아무것도 없을 경우
    if (list->head == NULL) {
        list->head = list->tail = new_node;
        *cursor = new_node;
        return;
    }

    // 커서가 NULL이면 맨 앞 삽입
    if (*cursor == NULL) {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
        *cursor = new_node;
        return;
    }

    // 일반적인 위치 삽입
    new_node->prev = *cursor;
    new_node->next = (*cursor)->next;

    if ((*cursor)->next != NULL)
        (*cursor)->next->prev = new_node;
    else
        list->tail = new_node;

    (*cursor)->next = new_node;
    *cursor = new_node;
}

// 노드 삭제 (커서 앞 노드 삭제)
void delete(List* list, Node** cursor) {
    if (*cursor == NULL) return;

    Node* to_delete = *cursor;

    if (to_delete->prev != NULL)
        to_delete->prev->next = to_delete->next;
    else
        list->head = to_delete->next;

    if (to_delete->next != NULL)
        to_delete->next->prev = to_delete->prev;
    else
        list->tail = to_delete->prev;

    *cursor = to_delete->prev;
    free(to_delete);
}

// 리스트 출력
void print_list(List* list) {
    Node* cur = list->head;
    while (cur != NULL) {
        printf("%c", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

// 메모리 해제
void free_list(List* list) {
    Node* cur = list->head;
    while (cur != NULL) {
        Node* temp = cur;
        cur = cur->next;
        free(temp);
    }
    list->head = list->tail = NULL;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        char input[MAX];
        scanf("%s", input);

        List list;
        init_list(&list);
        Node* cursor = NULL; // 커서 초기 위치는 가장 앞

        for (int i = 0; input[i]; i++) {
            char ch = input[i];
            if (ch == '<') {
                if (cursor != NULL) cursor = cursor->prev;
            }
            else if (ch == '>') {
                if (cursor == NULL) cursor = list.head;
                else if (cursor->next != NULL) cursor = cursor->next;
            }
            else if (ch == '-') {
                delete(&list, &cursor);
            }
            else {
                insert(&list, &cursor, ch);
            }
        }

        print_list(&list);
        free_list(&list);
    }
    return 0;
}
