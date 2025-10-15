#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

int findE(int* arr,int n, int k) {
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		if (k <= arr[mid]) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int* arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	printf(" %d", findE(arr,n, k));
	free(arr);
	return 0;
}