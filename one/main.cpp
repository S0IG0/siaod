#include <iostream>

void exchangeSort(int* arr, int length) {
	for (int i = 0; i < (length - 1); i++) 
	{		 
		for (int j = (i + 1); j < length; j++)
		{	
			if (arr[i] > arr[j])
			{
				std::swap(arr[i], arr[j]);
			}
		}
	}
}


int main()
{

	return 0;
}
