#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#pragma warning (disable:4996)

int n = 100000,Limit;
int Limits[] = { 1,100,500,1000 };
char* mode;

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
int findIndexOfMedianOfThree(int*A,int a,int b,int c) {
	if (A[b] <= A[a] && A[a] <= A[c] || A[c] <= A[a] && A[a] <= A[b]) return a;
	if (A[a] <= A[b] && A[b] <= A[c] || A[c] <= A[b] && A[b] <= A[a]) return b;
	return c;

}
int findPivot(int* A, int l, int r) {
	if (strcmp(mode, "deterministic1") == 0) return r;
	if (strcmp(mode, "randomized1") == 0)
		return l + rand() % (r - l + 1);
	if (r - l == 1) return l;
	int a, b, c;
	if (strcmp(mode, "deterministic3") == 0) {
		a = l; b = (l + r) / 2; c = r;
	}
	else{
		a= l + rand() % (r - l + 1);
		b= l + rand() % (r - l + 1);
		c= l + rand() % (r - l + 1);
	}
	return findIndexOfMedianOfThree(A,a, b, c);
}

void inPlacePartition(int* A, int l, int r, int k, int* a, int* b) {
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

void rQuickSort(int* A, int l, int r) {
	if (r - l >= Limit) {
		int k = findPivot(A, l, r);
		int a, b;
		inPlacePartition(A, l, r, k, &a, &b);
		rQuickSort(A, l, a - 1);
		rQuickSort(A, b + 1, r);
	}
}
void insertionSort(int* A, int n_) {
	for (int i = 1; i < n_; i++) {
		int key = A[i], j = i - 1;
		while (j >= 0 && A[j] > key) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
}

void quickSort(int* A, int n_) {
	rQuickSort(A, 0, n_ - 1);
	if (Limit > 1) insertionSort(A, n_);
	return;
}
int* createArray() {
	int* A = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) A[i] = 1 + rand() % n;
	return A;
}
int main() {
	srand((unsigned)time(NULL));
	char* modes[4] = { "deterministic1", "deterministic3", "randomized1", "randomized3" };
	int* A = createArray();

	printf("Limit\t\t결정적1\t\t결정적3\t\t무작위1\t\t무작위3\n");

	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);

	for (int i = 0; i < 4; i++) {
		Limit = Limits[i];
		double t[4];
		for (int j = 0; j < 4; j++) {
			mode = modes[j];
			int* A_ = (int*)malloc(n * sizeof(int));
			memcpy(A_, A, n * sizeof(int));

			LARGE_INTEGER start, end;
			QueryPerformanceCounter(&start);
			quickSort(A_,n);
			QueryPerformanceCounter(&end);
			t[j] = (double)(end.QuadPart - start.QuadPart) * 1000.0 / (double)freq.QuadPart;
			free(A_);
		}
		printf("%-8d\t%.8f\t%.8f\t%.8f\t%.8f\n",Limit,t[0],t[1],t[2],t[3]);
	}
	free(A);
	return 0;
}

