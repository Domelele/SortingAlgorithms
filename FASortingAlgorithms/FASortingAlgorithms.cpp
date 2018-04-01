// FASortingAlgorithms.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "FAFrameWork.h"
#include <cstdlib>
#include <ctime>

int* makeRandomArray(int size) {
	int* array = new int[size];
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		array[i] = (100.0 * rand()) / RAND_MAX;
	}
	return array;
}

void copyArray(int arr1[], int arr2[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr1[i] = arr2[i];
	}
}

int main() 
{
	FABubbleSort bubble;
	FAInsertionSort insertion;
	FASelectionSort selection;
	FAQuickSort quick;

	int size = 10;
	int *array = makeRandomArray(size);
	int arrayBackup[10];
	copyArray(arrayBackup, array, size);
	bubble.sort(array, size);
	bubble.printArray(array, size);
	copyArray(array, arrayBackup, size);
	insertion.sort(array, size);
	insertion.printArray(array, size);
	copyArray(array, arrayBackup, size);
	selection.sort(array, size);
	selection.printArray(array, size);
	copyArray(array, arrayBackup, size);
	quick.printArray(array, size);
	quick.sort(array, 0, size);
	quick.printArray(array, size);
	Sleep(100000);
	delete [] array;
	return 0;
}


