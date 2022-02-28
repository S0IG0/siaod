#include <iostream>
#include <functional>
#include <chrono>
#include <thread>
#include <fstream>
#include <map>
#include "Big_integer.h"

#define SEPARATOR ';'
#define PATH_RANDOM "dataRandom.csv"
#define PATH_ALL_SORTED "dataAllSorted.csv"
#define PATH_ALL_NOT_SORTED "dataAllNotSorted.csv"
#define PATH_TEST "dataTest.csv"

struct Sorts
{
	
	// insertionSort имеет сложность n^2, количество сравнений вычисляется по формуле n*(n-1)/2.
	static unsigned long* insertionSort(int* arr, int length, bool swapFlag = false) {
		unsigned long counterSwap = 0;
		unsigned long counterIf = 0;
		unsigned long counterIterations = 0;

		for (int i = 1; i < length; i++) {
			counterIterations = swapFlag ? counterIterations + 1 : counterIterations;

			// пока j > 0 и элемент под индексом [j - 1] больше чем элемент под индексом [j]
			for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
				counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
				// меняем местами элементы [j - 1] и [j]
				std::swap(arr[j - 1], arr[j]);
				// подсчет кол-ва перестоновок для length перменных
				counterSwap = swapFlag ? counterSwap + 1 : counterSwap;
				counterIf = swapFlag ? counterIf + 1 : counterIf;

			}
		}

		unsigned long* info = new unsigned long[3];
		info[0] = counterSwap;
		info[1] = counterIf;
		info[2] = counterIterations;

		return info;
	}

	// exchangeSort имеет сложность n^2, количество сравнений вычисляется по формуле n*(n-1)/2.
	static unsigned long* exchangeSort(int* arr, int length, bool swapFlag = false) {
		unsigned long counterSwap = 0;
		unsigned long counterIf = 0;
		unsigned long counterIterations = 0;

		// перебираем все элементы кроме последнего
		for (int i = 0; i < (length - 1); i++)
		{
			counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
			// перебераем все элементы от [(i + 1) до length) 
			for (int j = (i + 1); j < length; j++)
			{
				counterIterations = swapFlag ? counterIterations + 1 : counterIterations;

				// если элемент с индексом [i] > чем элемент с индексом [j] меняем их местами
				counterIf = counterIf ? counterIf + 1 : counterIf;
				if (arr[i] > arr[j]) {
					std::swap(arr[i], arr[j]);
					// подсчет кол-ва перестоновок для length перменных
					counterSwap = swapFlag ? counterSwap + 1 : counterSwap;
				}
			}
		}

		unsigned long* info = new unsigned long[3];
		info[0] = counterSwap;
		info[1] = counterIf;
		info[2] = counterIterations;
		return info;
	}

	// selectionSort имеет сложность n^2, количество сравнений вычисляется по формуле n*(n-1)/2.
	static unsigned long* selectionSort(int* arr, int length, bool swapFlag = false) {
		unsigned long counterSwap = 0;
		unsigned long counterIf = 0;
		unsigned long counterIterations = 0;

		// перебераем все элементы кроме последнего
		for (int i = 0; i < length - 1; ++i)
		{
			counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
			// изночально самым индекс самого минемального числа инициализируем текущем [i]
			int minIndex = i;
			// перебераем все элементы от [i до length) 
			for (int j = i + 1; j < length; ++j)
			{
				counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
				// если элемент с индексом [j] < чем элемент с индексом [minIndex], то перезаписываем minIndex
				counterIf = swapFlag ? counterIf + 1 : counterIf;
				if (arr[j] < arr[minIndex]) {
					minIndex = j;
				}
			}
			// меняем месатами элемент под интексом [i] с наименьшем элементом под индексом [minIndex]
			std::swap(arr[i], arr[minIndex]);
			// подсчет кол-ва перестоновок для length перменных
			counterSwap = swapFlag ? counterSwap + 1 : counterSwap;
		}

		unsigned long* info = new unsigned long[3];
		info[0] = counterSwap;
		info[1] = counterIf;
		info[2] = counterIterations;

		return info;
	}

	static unsigned long* shakerSort(int* arr, int length, bool swapFlag = false) {
		unsigned long counterSwap = 0;
		unsigned long counterIf = 0;
		unsigned long counterIterations = 0;

		bool swapped = true;
		int start = 0;
		int end = length - 1;

		while (swapped)
		{
			counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
			swapped = false;
			for (int i = start; i < end; i++)
			{
				counterIterations = swapFlag ? counterIterations + 1 : counterIterations;

				counterIf = swapFlag ? counterIf + 1 : counterIf;
				if (arr[i] > arr[i + 1]) {
					std::swap(arr[i], arr[i + 1]);
					swapped = true;

					counterSwap = swapFlag ? counterSwap + 1 : counterSwap;
				}
			}
			counterIf = swapFlag ? counterIf + 1 : counterIf;
			if (!swapped) {
				break;
			}
			swapped = false;
			end--;
			for (int i = end - 1; i >= start; i--)
			{
				counterIterations = swapFlag ? counterIterations + 1 : counterIterations;

				counterIf = swapFlag ? counterIf + 1 : counterIf;
				if (arr[i] > arr[i + 1]) {
					std::swap(arr[i], arr[i + 1]);
					swapped = true;

					counterSwap = swapFlag ? counterSwap + 1 : counterSwap;
				}
			}
			start++;
		}
		unsigned long* info = new unsigned long[3];
		info[0] = counterSwap;
		info[1] = counterIf;
		info[2] = counterIterations;

		return info;
	}

	static unsigned long* shellSort(int* arr, int length, bool swapFlag = false) {
		unsigned long counterSwap = 0;
		unsigned long counterIf = 0;
		unsigned long counterIterations = 0;

		int inc = length / 2;
		while (inc > 0)
		{
			counterIterations = swapFlag ? counterIterations + 1 : counterIterations;

			for (int i = 0; i < length - inc; i++)
			{
				counterIterations = swapFlag ? counterIterations + 1 : counterIterations;

				int j = i;
				while (j >= 0 && arr[j] > arr[j + inc])
				{
					counterIf = swapFlag ? counterIf + 1 : counterIf;

					std::swap(arr[j], arr[j + inc]);
					counterSwap = swapFlag ? counterSwap + 1 : counterSwap;
					j--;
				}
			}
			inc = inc / 2;
		}

		unsigned long* info = new unsigned long[3];
		info[0] = counterSwap;
		info[1] = counterIf;
		info[2] = counterIterations + counterSwap;

		return info;
	}

	static unsigned long* quickSort(int* arr, int length, bool swapFlag = false) {
		unsigned long counterSwap = 0;
		unsigned long counterIf = 0;
		unsigned long counterIterations = 0;

		quickSortFunction(0, length - 1, arr, length, counterSwap, counterIf, counterIterations, swapFlag);


		unsigned long* info = new unsigned long[3];
		info[0] = counterSwap;
		info[1] = counterIf;
		info[2] = counterIterations;
		return info;
	}

	static unsigned long* heapSort(int* arr, int length, bool swapFlag = false) {
		unsigned long counterSwap = 0;
		unsigned long counterIf = 0;
		unsigned long counterIterations = 0;


		for (int i = (length / 2) - 1; i >= 0; i--)
		{
			counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
			heapify(arr, i, length, counterSwap, counterIf, counterIterations, swapFlag);
		}
		for (int i = length - 1; i >= 1; i--)
		{
			counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
			std::swap(arr[0], arr[i]);
			counterSwap = swapFlag ? counterSwap + 1 : counterSwap;
			heapify(arr, 0, i, counterSwap, counterIf, counterIterations, swapFlag);
		}


		unsigned long* info = new unsigned long[3];
		info[0] = counterSwap;
		info[1] = counterIf;
		info[2] = counterIterations;

		return info;
	}

	static unsigned long* mergSort(int* arr, int length, bool swapFlag = false) {
		unsigned long counterSwap = 0;
		unsigned long counterIf = 0;
		unsigned long counterIterations = 0;

		//


		unsigned long* info = new unsigned long[3];
		info[0] = counterSwap;
		info[1] = counterIf;
		info[2] = counterIterations;

		return info;
	}

private:
	static void quickSortFunction(int start, int end, int* arr, int length,
		unsigned long& counterSwap,
		unsigned long& counterIf,
		unsigned long& counterIterations,
		bool swapFlag = false) {

		int left = start, rigth = end;
		int piv = arr[(left + rigth) / 2];
		while (left <= rigth)
		{
			counterIterations = swapFlag ? counterIterations + 1 : counterIterations;

			while (arr[left] < piv) {
				counterIf = swapFlag ? counterIf + 1 : counterIf;


				left++;
				counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
			}


			while (arr[rigth] > piv)
			{
				counterIf = swapFlag ? counterIf + 1 : counterIf;

				rigth--;
				counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
			}

			counterIf = swapFlag ? counterIf + 1 : counterIf;
			if (left <= rigth)
			{
				std::swap(arr[left++], arr[rigth--]);
				counterSwap = swapFlag ? counterSwap + 1 : counterSwap;
			}
		}
		counterIf = swapFlag ? counterIf + 1 : counterIf;
		if (start < rigth)
		{
			quickSortFunction(start, rigth, arr, length, counterSwap, counterIf, counterIterations, swapFlag);
		}
		counterIf = swapFlag ? counterIf + 1 : counterIf;
		if (end > left) {
			quickSortFunction(left, end, arr, length, counterSwap, counterIf, counterIterations, swapFlag);
		}
	}

	static void heapify(int* arr, int i, int length, 
		unsigned long& counterSwap,
		unsigned long& counterIf,
		unsigned long& counterIterations, 
		bool swapFlag = false) {

		int max = i;

		while (true)
		{
			counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
			
			int child = 2 * i + 1;

			counterIf = swapFlag ? counterIf + 1 : counterIf;
			if (child < length && arr[child] > arr[max])
			{
				max = child;
			}
			child++;

			counterIf = swapFlag ? counterIf + 1 : counterIf;
			if (child < length && arr[child] > arr[max])
			{
				max = child;
			}

			counterIf = swapFlag ? counterIf + 1 : counterIf;
			if (max == i)
			{
				break;
			}
			else
			{
				std::swap(arr[max], arr[i]);
				counterSwap = swapFlag ? counterSwap + 1 : counterSwap;
				i = max;
			}
		}
	}


};


// Функция для записи в файл типо CSV
void writeFileCSV(int length, unsigned long* info, double time, std::string typeSort, std::string path) {

	std::ofstream fileCreate;
	fileCreate.open(path, std::ios::app);
	fileCreate.close();

	std::ifstream file(path);
	if (!file.is_open()) {
		std::cout << "\nНе открылся\n";
	}
	else {
		if (file.peek() == EOF) {
			file.close();
			std::ofstream file;
			file.open(path, std::ios::app);
			file << "Кол-во элементов"				<< SEPARATOR
				<< "Кол-во элементов в ^ 2"			<< SEPARATOR
				<< "Кол-во перестановок"			<< SEPARATOR
				<< "Кол-во сравнений"				<< SEPARATOR
				<< "Сумма сравнений и перестановок" << SEPARATOR
				<< "Кол-во итераций"				<< SEPARATOR
				<< "Время на сортировку"			<< SEPARATOR
				<< "Тип сортировки" << "\n";
		}

		file.close();
		std::ofstream file;
		file.open(path, std::ios::app);
		std::cout.precision(8);
		big_integer INT = big_integer(length);


		file << length << SEPARATOR	
			 << INT * INT << SEPARATOR
		 	 << info[0]	<< SEPARATOR
		 	 << info[1] << SEPARATOR
			 << info[0] + info[1] << SEPARATOR
			 << info[2] << SEPARATOR
			 << std::fixed << time << SEPARATOR
			 << typeSort << "\n";
		/*
		info[0] = counterSwap;
		info[1] = counterIf;
		info[2] = counterIterations;
		*/
	}
	file.close();
}


// Функция для подсчета времени работы сортировки
void timeExecution(std::string path, int* arr, int length, std::string typeSort, std::function<unsigned long* (int*, int, bool)> sort, bool swapFlag = true) {

	auto start = std::chrono::high_resolution_clock::now();
	unsigned long* info = sort(arr, length, swapFlag);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;

	writeFileCSV(length, info, duration.count(), typeSort, path);
}

void test(std::string path, std::string sort, int start, int end, int step) {

	std::map<std::string, std::function<unsigned long* (int*, int, bool)>> sortsFunctions;
	sortsFunctions["shakerSort"] = Sorts::shakerSort;
	sortsFunctions["exchangeSort"] = Sorts::exchangeSort;
	sortsFunctions["insertionSort"] = Sorts::insertionSort;
	sortsFunctions["quickSort"] = Sorts::quickSort;
	sortsFunctions["shellSort"] = Sorts::shellSort;
	sortsFunctions["selectionSort"] = Sorts::selectionSort;
	sortsFunctions["heapSort"] = Sorts::heapSort;

	for (int n = start; n < end + 1; n += step)
	{
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			//arr[i] = rand() % 1000000; // Random
			arr[i] = i; // All Sorted
			//arr[i] = n - i; // All Not sorted
		}
		timeExecution(path, arr, n, sort, sortsFunctions[sort], true);
	}
}

void testResult(std::string path, std::string sort) {

	std::map<std::string, std::function<unsigned long* (int*, int, bool)>> sortsFunctions;
	sortsFunctions["shakerSort"] = Sorts::shakerSort;
	sortsFunctions["exchangeSort"] = Sorts::exchangeSort;
	sortsFunctions["insertionSort"] = Sorts::insertionSort;
	sortsFunctions["quickSort"] = Sorts::quickSort;
	sortsFunctions["shellSort"] = Sorts::shellSort;
	sortsFunctions["selectionSort"] = Sorts::selectionSort;
	sortsFunctions["heapSort"] = Sorts::heapSort;

	for (int n = 100; n < (1000000 + 1); n = n * 10)
	{
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % 1000000;
		}
		timeExecution(path, arr, n, sort, sortsFunctions[sort], true);
	}
}

int main() {
	setlocale(LC_ALL, "ru");

	//std::thread THshakerSort		(test,      "SortResult\\CSV\\shakerSort.csv",	 "shakerSort",		0, 1000001, 1000); //
	//std::thread THexchangeSort	(test,    "SortResult\\CSV\\exchangeSort.csv",	 "exchangeSort",	0, 1000001, 1000); //
	//std::thread THisertionSort	(test,    "SortResult\\CSV\\insertionSort.csv",	 "insertionSort",   0, 1000001, 1000); //
	//std::thread THquickSort		(test,		"SortResult\\CSV\\quickSort.csv",	 "quickSort",       0, 1000001, 1000); //
	//std::thread THshellSort		(test,		"SortResult\\CSV\\shellSort.csv",	 "shellSort",		0, 1000001, 1000); //
	//std::thread THselectionSort	(test,	"SortResult\\CSV\\selectionSort.csv",	 "selectionSort",	0, 1000001, 1000); //
	//std::thread THheapSort		(test,		"SortResult\\CSV\\heapSort.csv",	 "heapSort",		0, 1000001, 1000); //


	//THshakerSort.join();
	//THexchangeSort.join();
	//THisertionSort.join();
	//THquickSort.join();
	//THshellSort.join();
	//THselectionSort.join();
	//THheapSort.join();

	//int n = 10;
	//int* arr = new int[n];
	//for (int i = 0; i < n; i++)
	//{
	//	arr[i] = rand() % 100;
	//}

	//Sorts::exchangeSort(arr, n, false);

	//for (int i = 0; i < n; i++)
	//{
	//	std::cout << arr[i] << "\t";
	//}


	test("SortResult\\CSV\\ABOBA.csv", "quickSort", 0, 1000001, 100);

	return 0;
}
