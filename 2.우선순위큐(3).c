#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <Windows.h>
#pragma warning (disable:4996)

void selection_sort(int n,int*arr) {
	int temp;
	for (int j = 0; j < n - 1; j++) {
		int Max_i = 0;
		for (int i = 1; i < n - j; i++) if (arr[Max_i] < arr[i]) Max_i = i;
		temp = arr[n - j - 1];
		arr[n - j - 1] = arr[Max_i];
		arr[Max_i] = temp;
	}
}
void desc(int n, int* arr) {
	int temp;
	for (int j = 0; j < n - 1; j++) {
		int min_i = 0;
		for (int i = 1; i < n - j; i++) if (arr[min_i] > arr[i]) min_i = i;
		temp = arr[n - j - 1];
		arr[n - j - 1] = arr[min_i];
		arr[min_i] = temp;
	}
}

void insertion_sort(int n, int* arr) {
	for (int i = 1; i < n; i++) {
		int key = arr[i], j;
		for (j = i - 1; j >= 0&& arr[j] > key; j--) {
			if (arr[j] > key) arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}

int main() {
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;
	QueryPerformanceFrequency(&ticksPerSec);
	srand(time(NULL));
	int n, temp;
	scanf("%d", &n);
	int* A = (int*)malloc(n * sizeof(int));
	int* B = (int*)malloc(n * sizeof(int));
	if (A == 0 || B == 0) return -1;
	for (int i = 0; i < n; i++) {
		temp = rand();
		A[i] = temp; B[i] = temp;
	}
	//추가내용
	selection_sort(n,A); selection_sort(n,B);
	//
	QueryPerformanceCounter(&start);
	selection_sort(n, A);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.12fms\n", 1000 * ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
	
	QueryPerformanceCounter(&start);
	insertion_sort(n, B);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.12fms\n", 1000 * ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
	
	free(A); free(B);
	return 0;
}