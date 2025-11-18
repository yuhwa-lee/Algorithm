#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <Windows.h>
#pragma warning (disable:4996)

int H[101];
int n = 0;
void upHeap(int i) {
	if (i == 1) return;
	if (H[i] > H[i / 2]) {
		int temp = H[i];
		H[i] = H[i / 2];
		H[i / 2] = temp;
		upHeap(i / 2);
	}
	else return;

}
void downHeap(int i) {
	int left = 2 * i, right = 2 * i + 1;
	if (left>n) return;
	int greater = left;
	if (right <= n && H[right] > H[left])
		greater = right;
	if (H[i] > H[greater]) return;
	int temp = H[i];
	H[i] = H[greater];
	H[greater] = temp;
	downHeap(greater);
}
void insertItem(int key) {
	n++;
	H[n] = key;
	upHeap(n);
	return;
}
int removeMax() {
	int key = H[1];
	H[1] = H[n];
	n--;
	downHeap(1);
	return key;
}
void printHeap() {
	for (int i = 1; i <= n; i++)
		printf(" %d", H[i]);
	printf("\n");
}
void main() {
	char c;
	int item;
	while (1) {
		scanf(" %c", &c);
		if (c == 'i') {
			scanf(" %d", &item);
			insertItem(item);
			printf("0\n");
		}
		else if (c == 'd') printf("%d\n", removeMax());
		else if (c == 'p') printHeap();
		else return;
	}
}