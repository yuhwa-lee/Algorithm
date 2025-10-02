#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#pragma warning (disable:4996)

typedef struct listNode {
	int data;
	struct listNode* next;
}listNode;

typedef struct {
	listNode* head;
}list_h;

listNode* createNode(int value) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}
int size(list_h* L) {
	int cnt = 0;
	listNode* p = L->head;
	while (p) { p = p->next; cnt++; }
	return cnt;
}
void insertlast(list_h* L, int value) {
	listNode* node = createNode(value);
	if (L->head == NULL) {
		L->head = node;
		return;
	}
	listNode* cur = L->head;
	while (cur->next) cur = cur->next;
	cur->next = node;
}
int deletefirst(list_h* L) {
	int value = L->head->data;
	listNode* tmp = L->head;
	L->head = tmp->next;
	free(tmp);
	return value;
}
void printList(listNode* head) {
	listNode* cur = head;
	while (cur != NULL) {
		printf(" %d", cur->data);
		cur = cur->next;
	}
}
list_h* merge(list_h* L1, list_h* L2) {
	list_h* L = (list_h*)malloc(sizeof(list_h));
	L->head = NULL;
	while (L1->head && L2->head) {
		if (L1->head->data <= L2->head->data)
			insertlast(L, deletefirst(L1));
		else insertlast(L, deletefirst(L2));
	}
	while (L1->head) insertlast(L, deletefirst(L1));
	while (L2->head) insertlast(L, deletefirst(L2));
	return L;
}
list_h* partition(list_h* L, int k) {
	list_h* L1 = (list_h*)malloc(sizeof(list_h));
	L1->head = NULL;
	for (int i = 0; i < k; i++) {
		insertlast(L1, deletefirst(L));
	}
	return L1;
}
void mergeSort(list_h* L) {
	if (size(L)>1) {
		list_h*L1=partition(L,size(L)/2);
		mergeSort(L1);
		mergeSort(L);
		list_h*R=merge(L1, L);
		L->head = R->head;
	}
}

int main() {
	list_h* L = (list_h*)malloc(sizeof(list_h));
	L->head= NULL;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int value;
		scanf("%d", &value);
		insertlast(L, value);
	}
	mergeSort(L);
	printList(L->head);
	return 0;
}

