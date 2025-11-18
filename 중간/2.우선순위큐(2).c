#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <Windows.h>
#pragma warning (disable:4996)


int main() {
	int n, temp;
	scanf("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));
	if (arr == 0) return -1;
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) printf(" %d", arr[i]);
	free(arr);
	return 0;
}