#include "stdafx.h"
#include "FAQuickSort.h"
#include <cstdlib>
#include <ctime>
using namespace std;

void FAQuickSort::swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int FAQuickSort::sort(int *arr, int left, int right) {
	int l = left;
	int r = right - 1;
	int size = right - left;
	int sorts = 0;

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
				swap(&arr[l], &arr[r]);
				int sorts = 0;
				l++;
			}
		}
		return sorts + sort(arr, left, l) + sort(arr, r, right);
	}
}