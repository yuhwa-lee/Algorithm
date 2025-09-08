#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <Windows.h>
#pragma warning (disable:4996)


int main() {
	int n,temp;
	scanf("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));
	if (arr == 0) return -1;
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int j = 0; j < n-1; j++) {
		int Max_i = 0;
		for (int i = 1; i < n-j; i++) {
			if (arr[Max_i] < arr[i]) Max_i = i;
		}
		temp = arr[n-j - 1];
		arr[n-j - 1] = arr[Max_i];
		arr[Max_i] = temp;
	}
	for (int i = 0; i < n; i++) printf(" %d", arr[i]);
	free(arr);
	return 0;
}