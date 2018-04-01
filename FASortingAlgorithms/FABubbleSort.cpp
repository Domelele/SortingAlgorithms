#include "stdafx.h"
#include "FABubbleSort.h"

using namespace std;

void FABubbleSort::swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void FABubbleSort::sort(int arr[], int n) {
	bool swapped;
	for (int i = 0; i < n - 1; i++) {
		swapped = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

void FABubbleSort::printArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}