#include "Sorts.h"

#define SEPARATOR ';'
#define PATH_RANDOM "dataRandom.csv"
#define PATH_ALL_SORTED "dataAllSorted.csv"
#define PATH_ALL_NOT_SORTED "dataAllNotSorted.csv"
#define PATH_TEST "dataTest.csv"


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


	//test("SortResult\\CSV\\ABOBA.csv", "quickSort", 0, 1000001, 100);

	int n = 4;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}

	Sorts::mergeSort(arr, n, false);


	for (int i = 0; i < n; i++)
	{
		std::cout.width(7);
		std::cout << arr[i];
	}


	return 0;
}