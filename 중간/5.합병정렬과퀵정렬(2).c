#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable:4996)

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int findPivot(int *L,int l, int r) {
	return l + rand() % (r - l + 1);
}

void inPlacePartition(int* A,int l, int r, int k,int*a,int*b) {
	int p = A[k];
	swap(&A[k], &A[l]);
	int i0 = l, i1 = l + 1, i2 = r;
	while (i1 <= i2) {
		if (A[i1] < p) swap(&A[i0++], &A[i1++]);
		else if (A[i1] > p) swap(&A[i1], &A[i2--]);
		else i1++;
	}
	*a = i0, * b = i2;
}

void inPlaceQuickSort(int* L, int l, int r) {
	if (l >= r) return;
	int k = findPivot(L, l, r);
	int a, b;
	inPlacePartition(L, l, r, k,&a,&b);
	inPlaceQuickSort(L, l, a - 1);
	inPlaceQuickSort(L, b + 1, r);
}

int main() {
	int n;
	scanf("%d", &n);
	int* L = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) scanf("%d", &L[i]);
	inPlaceQuickSort(L, 0, n - 1);
	for (int i = 0; i < n; i++) printf(" %d", L[i]);
	return 0;
}

