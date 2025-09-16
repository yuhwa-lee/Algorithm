#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#pragma warning (disable:4996)

int findKthSmallest(int* L, int n, int k) {
	//입력 L을 보존하기 위해 내부 복사 H 사용
	int* H = (int*)malloc(sizeof(int) * (n + 1));
	if (H == 0) return -1;
	for (int i = 1; i <= n; i++) H[i] = L[i];
	//상향식 힙 정렬 O(n)
	for (int i = n / 2; i >= 1; i--) {
		int j = i;
		while (1) {
			int left = 2 * j, right = 2 * j + 1;
			if (left > n) break;
			int smaller = left;
			if (right <= n && H[right] < H[left])
				smaller = right;
			if (H[j] <= H[smaller]) break;
			int temp = H[j];
			H[j] = H[smaller];
			H[smaller] = temp;
			j = smaller;
		}
	}
	//k번째 작은 수 찾기 O(klogn)
    //k-1회 제거 동작 후, k==1에서 루트 반환
	int ans = -1; //return 전 H 메모리해제 위해 H[1]를 ans에 저장
	while (1) {
		if (k == 1) {
			ans = H[1];
			break;
		}
		H[1] = H[n];
		n--;
		int i = 1;
		while(1){
			int left = 2 * i, right = 2 * i + 1;
			if (left > n) break;
			int smaller = left;
			if (right <= n && H[right] < H[left])
				smaller = right;
			if (H[i] <= H[smaller]) break;
			int temp = H[i];
			H[i] = H[smaller];
			H[smaller] = temp;
			i = smaller;
		}
		k--;
	}
	free(H);
	return ans;
}
int* buildList(int n, int min, int max) {
	int* L = (int*)malloc(sizeof(int)*(n+1));
	if (L == 0) return NULL;
	for (int i = 1; i <= n; i++) {
		L[i] = min+(rand()%(max-min+1));
	}
	return L;
}
void writeList(int* L,int n) {
	for (int i = 1; i <= n; i++) {
		printf(" %d", L[i]);
	}
	printf("\n");
}

int main() {
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;
	QueryPerformanceFrequency(&ticksPerSec);
	srand(time(NULL));
	int *L=buildList(10, 1, 100);
	int output[5];
	int k, e; double t;
	writeList(L, 10);
	for (k = 1; k <= 3; k++) {
		output[k] = findKthSmallest(L, 10, k);
	}
	writeList(output, 3);
	free(L);
	L = buildList(100000, 1, 1000000);
	int karray[4] = {1,100,99900,99999};
	for (k = 0; k <= 3; k++) {
		QueryPerformanceCounter(&start);
		e = findKthSmallest(L, 100000, karray[k]);
		QueryPerformanceCounter(&end);
		diff.QuadPart = end.QuadPart - start.QuadPart;
		t = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;
		printf("%d %.12f\n", e, t);
	}
	free(L);
	return 0;
}