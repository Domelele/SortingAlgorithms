// FASortingAlgorithms.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "FAFrameWork.h"
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>

typedef std::chrono::high_resolution_clock Time;
auto start = Time::now();

std::chrono::duration<int, std::milli> deltaTime()
{
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> elapsed = finish - start;
	start = finish;
	return std::chrono::duration_cast<std::chrono::milliseconds>(elapsed);
}


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
	std::fstream LogFile("C:/Temp/SortingLog.txt");
	if (!LogFile)
		std::cout << "Error opening File!";
	FABubbleSort bubble;
	FAInsertionSort insertion;
	FASelectionSort selection;
	FAQuickSort quick;

	const int size = 100;
	int arrayBackup[size];
	int *array = makeRandomArray(size);
	copyArray(arrayBackup, array, size);
	bubble.sort(array, size);
	//bubble.printArray(array, size);
	copyArray(array, arrayBackup, size);
	insertion.sort(array, size);
	//insertion.printArray(array, size);
	copyArray(array, arrayBackup, size);
	selection.sort(array, size);
	//selection.printArray(array, size);
	copyArray(array, arrayBackup, size);
	quick.sort(array, 0, size);
	//quick.printArray(array, size);
	LogFile << deltaTime().count() << std::endl;
	Sleep(1000);
	delete [] array;
	LogFile.close();
	return 0;
}


