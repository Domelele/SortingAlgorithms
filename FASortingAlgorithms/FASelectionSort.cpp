#include "stdafx.h"
#include "FASelectionSort.h"

using namespace std;

void FASelectionSort::swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int FASelectionSort::sort(int arr[], int n) {
	int min; // index of smallest element
	int sorts = 0;
	for (int k = 0; k < n - 1; k++) {
		min = k;
		for (int j = k + 1; j < n; j++) {
			sorts++; //zählt Vergleichsoperationen
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		swap(&arr[min], &arr[k]);
	}
	return sorts;
}