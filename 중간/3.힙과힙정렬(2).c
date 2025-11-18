#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <Windows.h>
#pragma warning (disable:4996)

int H[101];
int n = 0;

void downHeap(int i) {
	int left = 2 * i, right = 2 * i + 1;
	if (left > n) return;
	int greater = left;
	if (right <= n && H[right] > H[left])
		greater = right;
	if (H[i] >= H[greater]) return;
	int temp = H[i];
	H[i] = H[greater];
	H[greater] = temp;
	downHeap(greater);
}
void rBuildHeap(int i) {
	if (i > n) return;
	rBuildHeap(2 * i);
	rBuildHeap(2 * i + 1);
	downHeap(i);
}
void BuildHeap() {
	for (int i = n / 2; i >= 1; i--)
		downHeap(i);
	return;
}
void printHeap() {
	for (int i = 1; i <= n; i++)
		printf(" %d", H[i]);
	printf("\n");
}
void main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &H[i]);
	rBuildHeap(1);
	//BuildHeap();
	printHeap();
}