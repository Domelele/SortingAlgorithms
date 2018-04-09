// FASortingAlgorithms.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "FAFrameWork.h"
#include <chrono>
#include <fstream>

typedef std::chrono::high_resolution_clock Time;
std::fstream LogFile;
auto start = Time::now();
auto programstart = start;

std::chrono::duration<int, std::nano> deltaTime()
{
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> elapsed = finish - start;
	start = finish;
	return std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed);
}


int* makeRandomArray(int size) {
	int* array = new int[size];
	std::chrono::microseconds ms = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch());
	srand(ms.count());
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 10000;
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

void printArray(int arr[], int size) {
	LogFile << "Array: ";
	for (int i = 0; i < size; i++)
		LogFile << arr[i] << " ";
	LogFile << std::endl;
}

int main() 
{
	LogFile.open("C:/Temp/SortingLog.txt", std::fstream::out | std::fstream::trunc);
	if (!LogFile)
	{
		std::cout << "Error opening File!";
		Sleep(5000);
		return 1;
	}
	FABubbleSort bubble;
	FAInsertionSort insertion;
	FASelectionSort selection;
	FAQuickSort quick;
	int countProbes;
	std::cout << "Anzahl Versuche?\n";
	std::cin >> countProbes;
	const int size = 100;
	int arrayBackup[size];
	for (int i = 0; i < countProbes; i++)
	{
		int *array = makeRandomArray(size);
		copyArray(arrayBackup, array, size);
		printArray(array, size);
		start = Time::now();
		{
			copyArray(array, arrayBackup, size);
			LogFile << "Copytime: " << deltaTime().count() << std::endl;
		}//Zum prüfen ob dadurch Zeitunterschiede entstehen
		LogFile << "BubbleSort Swaps: " << bubble.sort(array, size) << std::endl;
		LogFile << "BubbleSort Zeit: " << deltaTime().count() << std::endl;
		copyArray(array, arrayBackup, size);
		LogFile << "InsertionSort Swaps: " << insertion.sort(array, size) << std::endl;
		LogFile << "InsertionSort Zeit: " << deltaTime().count() << std::endl;
		copyArray(array, arrayBackup, size);
		LogFile << "SelectionSort Swaps: " << selection.sort(array, size) << std::endl;
		LogFile << "SelectionSort Zeit: " << deltaTime().count() << std::endl;
		copyArray(array, arrayBackup, size);
		LogFile << "Quicksort Swaps: " << quick.sort(array, 0, size) << std::endl;
		LogFile << "QuickSort Zeit: " << deltaTime().count() << std::endl;
		LogFile << "Sorted ";
		printArray(array, size);
		delete[] array;
		LogFile << "\n\n";
	}
	LogFile.close();
	return 0;
}


