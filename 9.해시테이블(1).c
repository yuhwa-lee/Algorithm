#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct Node {
	int element;
	struct Node* next;
}node;

void insertItem(node* hash, int M,int k) {
	node *New=(node*)malloc(sizeof(node));
	New->element = k;
	New->next = hash[k % M].next;
	hash[k % M].next= New;
	return;
}
int findElement(node* hash, int M, int k) {
	int v = k % M,n=1;
	for (node* cur = hash[v].next; cur; cur = cur->next, n++) {
		if (cur->element == k) return n;
	}
	return 0;
}
int removeElement(node* hash, int M, int k) {
	int v = k % M;
	node* prev = &hash[v];
	node* cur = hash[v].next;
	int n = 1;
	while (cur) {
		if (cur->element == k) {
			prev->next = cur->next;
			return n;
		}
		prev = cur;
		cur = cur->next;
		n++;
	}
	return 0;
}
void print(node*hash,int M) {
	for (int i = 0; i < M; i++) {
		for (node* cur = hash[i].next; cur; cur = cur->next) {
			printf(" %d", cur->element);
		}
	}
	printf("\n");
}
int main() {
	int M, x, v; char ch;
	scanf("%d", &M);
	node* A = (node*)malloc(M * sizeof(node));
	for (int i = 0; i < M; i++) A[i].next = NULL;
	while (1) {
		scanf(" %c", &ch);
		switch (ch) {
		case 'i':
			scanf("%d", &x);
			insertItem(A, M, x);
			break;
		case 's':
			scanf("%d", &x);
			printf("%d\n",findElement(A, M, x));
			break;
		case 'd':
			scanf("%d", &x);
			printf("%d\n",removeElement(A, M, x));
			break;
		case 'p':
			print(A,M);
			break;
		case 'e':
			return 0;
		}
	}

	return 0;
}
