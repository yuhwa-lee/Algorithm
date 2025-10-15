#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

int main() {
	int a, b, n, k;
	scanf("%d %d %d", &a, &b, &n);
	getchar();
	for (int i = 0; i < n; i++) {
		char ch;
		int mid = (a + b) / 2;
		scanf("%c", &ch);
		if (ch == 'Y') a = mid + 1;
		else b = mid;
	}
	printf("%d", a);
	return 0;
}