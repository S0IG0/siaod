#include <iostream>

struct Sorts
{
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
};


int main()
{
	int n = 10;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 1000;
	}

	Sorts::quickSort(arr, n, false);

	for (int i = 0; i < n; i++)
	{
		std::cout.width(7);
		std::cout << arr[i];
	}

    return 0;
}
