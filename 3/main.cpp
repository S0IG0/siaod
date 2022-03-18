#include <iostream>

struct Sorts
{
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

	//функция, сливающая массивы
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



	//рекурсивная процедура сортировки
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
			Merge(A, start, stop, size, counterSwap, counterIf, counterIterations, swapFlag);							//слияние двух частей
		}
	};


};


int main()
{
	int n = 10;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 1000;
	}

	Sorts::mergeSort(arr, n, false);

	for (int i = 0; i < n; i++)
	{
		std::cout.width(7);
		std::cout << arr[i];
	}

    return 0;
}
