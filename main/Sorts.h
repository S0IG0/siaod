#include <iostream>
#include <functional>
#include <chrono>
#include <thread>
#include <fstream>
#include <map>
#include "Big_integer.h"

struct Sorts
{

	// insertionSort ����� ��������� n^2, ���������� ��������� ����������� �� ������� n*(n-1)/2.
	static unsigned long* insertionSort(int* arr, int length, bool swapFlag = false) {
		unsigned long counterSwap = 0;
		unsigned long counterIf = 0;
		unsigned long counterIterations = 0;

		for (int i = 1; i < length; i++) {
			counterIterations = swapFlag ? counterIterations + 1 : counterIterations;

			// ���� j > 0 � ������� ��� �������� [j - 1] ������ ��� ������� ��� �������� [j]
			for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
				counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
				// ������ ������� �������� [j - 1] � [j]
				std::swap(arr[j - 1], arr[j]);
				// ������� ���-�� ������������ ��� length ���������
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

	// exchangeSort ����� ��������� n^2, ���������� ��������� ����������� �� ������� n*(n-1)/2.
	static unsigned long* exchangeSort(int* arr, int length, bool swapFlag = false) {
		unsigned long counterSwap = 0;
		unsigned long counterIf = 0;
		unsigned long counterIterations = 0;

		// ���������� ��� �������� ����� ����������
		for (int i = 0; i < (length - 1); i++)
		{
			counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
			// ���������� ��� �������� �� [(i + 1) �� length) 
			for (int j = (i + 1); j < length; j++)
			{
				counterIterations = swapFlag ? counterIterations + 1 : counterIterations;

				// ���� ������� � �������� [i] > ��� ������� � �������� [j] ������ �� �������
				counterIf = counterIf ? counterIf + 1 : counterIf;
				if (arr[i] > arr[j]) {
					std::swap(arr[i], arr[j]);
					// ������� ���-�� ������������ ��� length ���������
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

	// selectionSort ����� ��������� n^2, ���������� ��������� ����������� �� ������� n*(n-1)/2.
	static unsigned long* selectionSort(int* arr, int length, bool swapFlag = false) {
		unsigned long counterSwap = 0;
		unsigned long counterIf = 0;
		unsigned long counterIterations = 0;

		// ���������� ��� �������� ����� ����������
		for (int i = 0; i < length - 1; ++i)
		{
			counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
			// ���������� ����� ������ ������ ������������ ����� �������������� ������� [i]
			int minIndex = i;
			// ���������� ��� �������� �� [i �� length) 
			for (int j = i + 1; j < length; ++j)
			{
				counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
				// ���� ������� � �������� [j] < ��� ������� � �������� [minIndex], �� �������������� minIndex
				counterIf = swapFlag ? counterIf + 1 : counterIf;
				if (arr[j] < arr[minIndex]) {
					minIndex = j;
				}
			}
			// ������ �������� ������� ��� �������� [i] � ���������� ��������� ��� �������� [minIndex]
			std::swap(arr[i], arr[minIndex]);
			// ������� ���-�� ������������ ��� length ���������
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
		int piv = arr[(left + rigth) / 2]; // �������� 
		while (left <= rigth)
		{
			counterIterations = swapFlag ? counterIterations + 1 : counterIterations;

			while (arr[left] < piv) { // ������� ������� ������� ������ PIV
				counterIf = swapFlag ? counterIf + 1 : counterIf;


				left++;
				counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
			}


			while (arr[rigth] > piv) // ������� ������� ������� ������� ��� PIV
			{
				counterIf = swapFlag ? counterIf + 1 : counterIf;

				rigth--;
				counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
			}

			counterIf = swapFlag ? counterIf + 1 : counterIf;
			if (left <= rigth) // ���� ������ ������ �������� ������ ��� ������� 
			{
				std::swap(arr[left++], arr[rigth--]); // ������ �������� �������  � ����������� left �� 1 � rigth �� -1
				counterSwap = swapFlag ? counterSwap + 1 : counterSwap;
			}
		}
		counterIf = swapFlag ? counterIf + 1 : counterIf;
		if (start < rigth)
		{
			quickSortFunction(start, rigth, arr, length, counterSwap, counterIf, counterIterations, swapFlag);
			// ����� ������ ����� 
		}
		counterIf = swapFlag ? counterIf + 1 : counterIf;
		if (end > left) {
			quickSortFunction(left, end, arr, length, counterSwap, counterIf, counterIterations, swapFlag);
			// ����� ����� ����� 
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

	//�������, ��������� �������
	static void Merge(int* Arr, int startIndex, int stopIndex, int size, 
		unsigned long& counterSwap,
		unsigned long& counterIf,
		unsigned long& counterIterations,
		bool swapFlag = false)
	{
		int middle = (startIndex + stopIndex) / 2; //���������� �������� ��������
		int start = startIndex; //������ ����� �����;
		int final = middle + 1; //������ ������ �����

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

		//����������� ���������� � ������
		for (int i = startIndex; i <= stopIndex; i++)
		{
			counterIterations = swapFlag ? counterIterations + 1 : counterIterations;

			Arr[i] = tempArr[i];
			counterSwap = swapFlag ? counterSwap + 1 : counterSwap;
		}

		delete[]tempArr;
	};



	//����������� ��������� ����������
	static void MergeFunction(int* A, int start, int stop, int size,
		unsigned long& counterSwap,
		unsigned long& counterIf,
		unsigned long& counterIterations,
		bool swapFlag = false)
	{
		if (start < stop)
		{
			MergeFunction(A, start, (start + stop) / 2, size, counterSwap, counterIf, counterIterations, swapFlag);		//���������� ����� �����
			MergeFunction(A, (start + stop) / 2 + 1, stop, size, counterSwap, counterIf, counterIterations, swapFlag);	//���������� ������ �����
			Merge(A, start, stop, size, counterSwap, counterIf, counterIterations, swapFlag);							//������� ���� ������
		}
	};


};
