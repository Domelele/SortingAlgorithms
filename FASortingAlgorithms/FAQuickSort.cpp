#include "stdafx.h"
#include "FAQuickSort.h"
#include <cstdlib>
#include <ctime>
using namespace std;

void FAQuickSort::swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
void FAQuickSort::sort(int *arr, int left, int right) {
	int l = left;
	int r = right - 1;
	int size = right - left;

	if (size > 1) {
		int pivot = arr[rand() % size + l];
		while (l < r) {
			while (arr[r] > pivot && r > l) {
				r--;
			}
			while (arr[l] < pivot && l <= r) {
				l++;
			}
			if (l < r) {
				swap(arr[l], arr[r]);
				l++;
			}
		}
		sort(arr, left, l);
		sort(arr, r, right);
	}
}


//Create a random array
/*int* FAQuickSort::makeRandomArray(int size) {
	int* array = new int[size];
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		array[i] = (100.0 * rand()) / RAND_MAX;
	}
	return array;
}
*/
void FAQuickSort::printArray(int *arr, int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}