#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

int rfindE(int* arr, int l, int r,int k) {
	if (l > r) return r;
	int mid = (l + r) / 2;
	if (k == arr[mid]) return mid;
	if (k < arr[mid]) rfindE(arr, l, mid-1, k);
	else rfindE(arr, mid + 1, r, k);
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int* arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	printf(" %d", rfindE(arr, 0,n-1, k));
	free(arr);
	return 0;
}