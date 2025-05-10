#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define LINE 21
#define MAX 500000

typedef struct Nolisten {

    char name[LINE];

} Nolisten;

typedef struct Nosee {

    char name[LINE];
}Nosee;

typedef struct Nolistenandsee {

    char name[LINE];

} Nolistenandsee;

// strcmp 기반 구조체 비교 함수
int compare_struct(const void* a, const void* b) {
    return strcmp(((Nolisten*)a)->name, ((Nolisten*)b)->name);
}


int main(void) {

    int N = 0;
    int M = 0;
    int count = 0;


    scanf("%d", &N);
    scanf("%d", &M);
    getchar();

    //구조체 메모리 공간 할당
    Nolisten* nolistenlist = malloc(sizeof(Nolisten) * N);
    Nosee* noseelist = malloc(sizeof(Nosee) * M);
    Nolistenandsee* nolistenandseelist = malloc(sizeof(Nolistenandsee) * MAX);


    //입력받기
    for (int i = 0; i < N; i++)
    {
        fgets(nolistenlist[i].name, LINE, stdin);
        nolistenlist[i].name[strcspn(nolistenlist[i].name, "\n")] = '\0';  // 개행 제거
    }
    for (int j = 0; j < M; j++)
    {
        fgets(noseelist[j].name, LINE, stdin);
        noseelist[j].name[strcspn(noseelist[j].name, "\n")] = '\0';  // 개행 제거
    }

    //듣도보도 못한 놈인지 확인
    qsort(nolistenlist, N, sizeof(Nolisten), compare_struct);

    for (int j = 0; j < M; j++)
    {
        Nolisten key;
        strcpy(key.name, noseelist[j].name);

        Nolisten* found = bsearch(&key, nolistenlist, N, sizeof(Nolisten), compare_struct);
        if (found != NULL) {
            strcpy(nolistenandseelist[count++].name, key.name);
        }
    }

    qsort(nolistenandseelist, count, sizeof(Nolistenandsee), compare_struct);

    // 정답 출력
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%s\n", nolistenandseelist[i].name);
    }


    return 0;
}

// 시간초과 코드
/*#define _CRT_SECURE_NO_WARNINGS
 #include <stdio.h>
 # include <stdlib.h>
 #include <string.h>

#define LINE 21
#define MAX 500000

typedef struct Nolisten {

    char name[LINE];

} Nolisten;

typedef struct Nosee {

    char name[LINE];
}Nosee;

typedef struct Nolistenandsee {

    char name[LINE];

} Nolistenandsee;

int compare_name(const void* a, const void* b) {
    const Nolistenandsee* na = (const Nolistenandsee*)a;
    const Nolistenandsee* nb = (const Nolistenandsee*)b;
    return strcmp(na->name, nb->name);
}

int main(void) {

    int N = 0;
    int M = 0;
    int count = 0;


    scanf("%d", &N);
    scanf("%d", &M);
    getchar();

    //구조체 메모리 공간 할당
    Nolisten* nolistenlist = malloc(sizeof(Nolisten) * N);
    Nosee* noseelist = malloc(sizeof(Nosee) * M);
    Nolistenandsee* nolistenandseelist = malloc(sizeof(Nolistenandsee) * MAX);


   //입력받기
    for (int i = 0; i < N; i++)
    {
        fgets(nolistenlist[i].name, LINE, stdin);
        nolistenlist[i].name[strcspn(nolistenlist[i].name, "\n")] = '\0';  // 개행 제거
    }
    for (int j = 0; j < M; j++)
    {
        fgets(noseelist[j].name, LINE, stdin);
        noseelist[j].name[strcspn(noseelist[j].name, "\n")] = '\0';  // 개행 제거
    }

    //듣도보도 못한 놈인지 확인
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (strlen(nolistenlist[i].name) == strlen(noseelist[j].name))
            {
                if (strcmp(nolistenlist[i].name, noseelist[j].name) == 0)
                {
                    strcpy(nolistenandseelist[count].name, nolistenlist[i].name);
                    count++;

                }
           }
        }
    }

    // 듣보잡 이름 정렬
    qsort(nolistenandseelist, count, sizeof(Nolistenandsee), compare_name);

    // 정답 출력
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%s\n", nolistenandseelist[i].name);
    }


    return 0;
}
*/