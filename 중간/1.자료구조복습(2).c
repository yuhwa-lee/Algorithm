#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning (disable:4996)

typedef struct node {
	struct node* left;
	int id;
	struct node* right;
}Node;

Node* createNode(int id) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->id = id;
	newNode->left = newNode->right = NULL;
	return newNode;
}
Node* find(Node* root, int id) {
	if (root == NULL) return NULL;
	if (root->id == id)return root;
	Node* left = find(root->left, id);
	if (left != NULL) return left;
	return find(root->right, id);
}

int main() {
	int N;
	scanf("%d", &N);
	Node* root = NULL;
	for (int i = 0; i < N; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		Node* parent;
		if (root == NULL) {
			root = createNode(x);
			parent = root;
		}
		else parent = find(root, x);
		if (y) {
			Node* left = createNode(y);
			parent->left = left;
		}
		if (z) {
			Node* right = createNode(z);
			parent->right = right;
		}
	}
	int S;
	scanf("%d", &S);
	char path[101];
	for (int i = 0; i < S; i++) {
		scanf("%s", path);
		Node* cur = root;
		printf("%d", cur->id);
		for (int j = 0; path[j]; j++) {
			if (path[j] == 'L') cur = cur->left;
			else if (path[j] == 'R') cur = cur->right;
			printf(" %d", cur->id);
		}
		printf("\n");
	}
	return 0;
}