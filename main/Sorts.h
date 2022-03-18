#include <iostream>
#include <functional>
#include <chrono>
#include <thread>
#include <fstream>
#include <map>
#include "Big_integer.h"

struct Sorts
{

	// insertionSort имеет сложность n^2, количество сравнений вычисл€етс€ по формуле n*(n-1)/2.
	static unsigned long* insertionSort(int* arr, int length, bool swapFlag = false) {
		unsigned long counterSwap = 0;
		unsigned long counterIf = 0;
		unsigned long counterIterations = 0;

		for (int i = 1; i < length; i++) {
			counterIterations = swapFlag ? counterIterations + 1 : counterIterations;

			// пока j > 0 и элемент под индексом [j - 1] больше чем элемент под индексом [j]
			for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
				counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
				// мен€ем местами элементы [j - 1] и [j]
				std::swap(arr[j - 1], arr[j]);
				// подсчет кол-ва перестоновок дл€ length перменных
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

	// exchangeSort имеет сложность n^2, количество сравнений вычисл€етс€ по формуле n*(n-1)/2.
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

				// если элемент с индексом [i] > чем элемент с индексом [j] мен€ем их местами
				counterIf = counterIf ? counterIf + 1 : counterIf;
				if (arr[i] > arr[j]) {
					std::swap(arr[i], arr[j]);
					// подсчет кол-ва перестоновок дл€ length перменных
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

	// selectionSort имеет сложность n^2, количество сравнений вычисл€етс€ по формуле n*(n-1)/2.
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
			// мен€ем месатами элемент под интексом [i] с наименьшем элементом под индексом [minIndex]
			std::swap(arr[i], arr[minIndex]);
			// подсчет кол-ва перестоновок дл€ length перменных
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


	static unsigned long* mergeSort(int* Arr, int size, bool swapFlag = false)
	{
		unsigned long counterSwap = 0;
		unsigned long counterIf = 0;
		unsigned long counterIterations = 0;

		MergeFunction(Arr, 0, size - 1, size - 1, counterSwap, counterIf, counterIterations, swapFlag);

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
		int piv = arr[(left + rigth) / 2]; // —ередина 
		while (left <= rigth)
		{
			counterIterations = swapFlag ? counterIterations + 1 : counterIterations;

			while (arr[left] < piv) { // Ќаходим элемент который больше PIV
				counterIf = swapFlag ? counterIf + 1 : counterIf;


				left++;
				counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
			}


			while (arr[rigth] > piv) // Ќаходим элемент который маеньше чем PIV
			{
				counterIf = swapFlag ? counterIf + 1 : counterIf;

				rigth--;
				counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
			}

			counterIf = swapFlag ? counterIf + 1 : counterIf;
			if (left <= rigth) // ≈сле индекс левого элемента меньше чем правого 
			{
				std::swap(arr[left++], arr[rigth--]); // ћен€ем элементы местами  и увеличиваем left на 1 и rigth на -1
				counterSwap = swapFlag ? counterSwap + 1 : counterSwap;
			}
		}
		counterIf = swapFlag ? counterIf + 1 : counterIf;
		if (start < rigth)
		{
			quickSortFunction(start, rigth, arr, length, counterSwap, counterIf, counterIterations, swapFlag);
			// Ѕерем правую часть 
		}
		counterIf = swapFlag ? counterIf + 1 : counterIf;
		if (end > left) {
			quickSortFunction(left, end, arr, length, counterSwap, counterIf, counterIterations, swapFlag);
			// Ѕерем левую часть 
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

	//функци€, сливающа€ массивы
	static void Merge(int* Arr, int startIndex, int stopIndex, int size, 
		unsigned long& counterSwap,
		unsigned long& counterIf,
		unsigned long& counterIterations,
		bool swapFlag = false)
	{
		int middle = (startIndex + stopIndex) / 2; //вычисление среднего элемента
		int start = startIndex; //начало левой части;
		int final = middle + 1; //начало правой части

		int* tempArr = new int[size + 1];

		int index = 0, temp = 0;
		for (int i = startIndex; i <= stopIndex; i++)
		{
			counterIterations = swapFlag ? counterIterations + 1 : counterIterations;

			counterIf = swapFlag ? counterIf + 1 : counterIf;
			if ((start <= middle) && ((final > stopIndex) || (Arr[start] < Arr[final])))
			{
				tempArr[i] = Arr[start];
				start++;
			}
			else
			{
				tempArr[i] = Arr[final];
				final++;
			}
		}

		//возвращение результата в список
		for (int i = startIndex; i <= stopIndex; i++)
		{
			counterIterations = swapFlag ? counterIterations + 1 : counterIterations;

			Arr[i] = tempArr[i];
			counterSwap = swapFlag ? counterSwap + 1 : counterSwap;
		}

		delete[]tempArr;
	};



	//рекурсивна€ процедура сортировки
	static void MergeFunction(int* A, int start, int stop, int size,
		unsigned long& counterSwap,
		unsigned long& counterIf,
		unsigned long& counterIterations,
		bool swapFlag = false)
	{
		if (start < stop)
		{
			MergeFunction(A, start, (start + stop) / 2, size, counterSwap, counterIf, counterIterations, swapFlag);		//сортировка левой части
			MergeFunction(A, (start + stop) / 2 + 1, stop, size, counterSwap, counterIf, counterIterations, swapFlag);	//сортировка правой части
			Merge(A, start, stop, size, counterSwap, counterIf, counterIterations, swapFlag);							//сли€ние двух частей
		}
	};


};
