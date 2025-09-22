#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#pragma warning (disable:4996)

int H[101];
int n;

void printArray() {
	for (int i = 1; i <= n; i++) printf(" %d", H[i]);
}
void downHeap(int i) {
	int left = 2 * i, right = 2 * i + 1;
	if (left > n) return;
	int greater = left;
	if (right <= n && H[right] > H[left])
		greater = right;
	if (H[i] >= H[greater]) return; 
	// '>'만 있으면 중복키 이슈처리 못함 '>='써야함
	//문제(1),(2)차이 단지 그것뿐
	int temp = H[i];
	H[i] = H[greater];
	H[greater] = temp;
	downHeap(greater);
}

void BuildHeap() {
	for (int i = n / 2; i >= 1; i--)
		downHeap(i);
	return;
}
void inPlaceHeapSort() {
	BuildHeap();
	int N = n;
	for (int i = n; n >= 2;i--) {
		int temp = H[1];
		H[1] = H[i];
		H[i] = temp;
		n--;
		downHeap(1);
	}
	n = N;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &H[i]);
	inPlaceHeapSort();
	printArray();
	return 0;
}