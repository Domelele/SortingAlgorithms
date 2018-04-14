#include "stdafx.h"
#include "FABubbleSort.h"

using namespace std;

void FABubbleSort::swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int FABubbleSort::sort(int arr[], int n) {
	bool swapped;
	int sorts = 0;
	for (int i = 0; i < n - 1; i++) {
		swapped = false;
		for (int j = 0; j < n - i - 1; j++) {
			sorts++; //zählt Vergleichsoperationen
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
	return sorts;
}