#include "stdafx.h"
#include "FAInsertionSort.h"

using namespace std;

void FAInsertionSort::swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int FAInsertionSort::sort(int arr[], int n) {
	int i, j;
	int sorts = 0;
	for (i = 1; i < n; i++) {
		j = i;
		while (j > 0 && arr[j - 1] > arr[j]) {
			sorts++; //zählt Vergleichsoperationen
			swap(&arr[j], &arr[j - 1]);
			j--;
		}
	}
	return sorts;
}