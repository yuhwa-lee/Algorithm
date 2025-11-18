#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#pragma warning (disable:4996)

typedef struct listNode {
    struct listNode* llink;
    char data;
    struct listNode* rlink;
}listNode;

typedef struct {
    listNode* head;
}list_h;

void add(list_h* DL, int r, char e) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = e;
    newNode->rlink = NULL;
    newNode->llink = NULL;
    if (DL->head == NULL) {
        if (r != 1) {
            printf("invalid position\n"); return;
        }
        DL->head = newNode;
        return;
    }
    if (r == 1) {
        newNode->rlink = DL->head;
        DL->head->llink = newNode;
        DL->head = newNode;
        return;
    }
    listNode* p = DL->head; int i;
    for (i = 1; i < r - 1 && p->rlink != NULL; i++) {
        p = p->rlink;
    }

    if (i != r - 1) {
        printf("invalid position\n");
        free(newNode);
        return;
    }
    newNode->rlink = p->rlink;
    if (newNode->rlink != NULL)
        newNode->rlink->llink = newNode;
    p->rlink = newNode;
    newNode->llink = p;
}
void delete(list_h* DL, int r) {
    if (DL->head == NULL || r < 1) {
        printf("invalid position\n");
        return;
    }

    listNode* p = DL->head;
    int i;
    for (i = 1; i < r && p != NULL; i++) {
        p = p->rlink;
    }

    if (p == NULL) {
        printf("invalid position\n");
        return;
    }


    if (p == DL->head) {
        DL->head = p->rlink;
        if (DL->head != NULL)
            DL->head->llink = NULL;
    }
    else {
        p->llink->rlink = p->rlink;
        if (p->rlink != NULL)
            p->rlink->llink = p->llink;
    }
    free(p);
}
void get(list_h* DL, int r) {
    if (DL->head == NULL || r < 1) {
        printf("invalid position\n");
        return;
    }

    listNode* p = DL->head;
    int i;
    for (i = 1; i < r && p != NULL; i++) {
        p = p->rlink;
    }

    if (p == NULL) {
        printf("invalid position\n");
        return;
    }

    printf("%c\n", p->data);
}
void print(list_h* DL) {
    listNode* p = DL->head;
    while (p != NULL) {
        printf("%c", p->data);
        p = p->rlink;
    }
    printf("\n");
}

int main() {
    list_h* DL = (list_h*)malloc(sizeof(list_h));
    DL->head = NULL;
    int N;
    scanf("%d", &N); getchar();

    for (int i = 0; i < N; i++) {
        char ch;
        ch = getchar();
        if (ch == '\n') { ch = getchar(); }

        if (ch == 'P') {
            print(DL);
            getchar();
        }
        else if (ch == 'A') {
            int r; char e;
            scanf("%d %c", &r, &e); getchar();
            add(DL, r, e);
        }
        else if (ch == 'D') {
            int r;
            scanf("%d", &r); getchar();
            delete(DL, r);
        }
        else if (ch == 'G') {
            int r;
            scanf("%d", &r); getchar();
            get(DL, r);
        }
    }

    return 0;
}


