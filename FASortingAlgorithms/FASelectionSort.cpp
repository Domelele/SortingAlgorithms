#include "stdafx.h"
#include "FASelectionSort.h"

using namespace std;

void FASelectionSort::swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void FASelectionSort::sort(int arr[], int n) {
	int min; // index of smallest element
	for (int k = 0; k < n - 1; k++) {
		min = k;
		for (int j = k + 1; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		swap(&arr[min], &arr[k]);
	}
}

void FASelectionSort::printArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}