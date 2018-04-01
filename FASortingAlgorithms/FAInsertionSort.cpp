#include "stdafx.h"
#include "FAInsertionSort.h"

using namespace std;

void FAInsertionSort::swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void FAInsertionSort::sort(int arr[], int n) {
	int i, j;
	for (i = 1; i < n; i++) {
		j = i;
		while (j > 0 && arr[j - 1] > arr[j]) {
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}

void FAInsertionSort::printArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
