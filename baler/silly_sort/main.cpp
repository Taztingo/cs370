#include <iostream>

void swap(int* array, int index1, int index2)
{
	int temp;
	temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}

void printArray(int* array, int size)
{
	for(int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
	
	std::cout << "\n";
}

int sillySort(int* array, int size)
{
	int minSum = 0;
	bool firstSwap = true;

	printArray(array, size);

	for(int i = 0; i < size; i++)
	{
		for(int i2 = i + 1; i2 < size; i2++)
		{
			//Found a swappable pair
			if(array[i] > array[i2])
			{
				int sum = array[i] + array[i2];
				std::cout << "Swapping: " << array[i] << " and " << array[i2]  << " (" << sum << ")" << std::endl;

				//Temporary swap the array to call silly on it
				swap(array, i, i2);

				//Calculate silly on new array
				int minSilly = sillySort(array, size);

				//Found a new minimum
				if((minSilly + sum) < minSum || firstSwap)
				{
					firstSwap = false;
					minSum = minSilly + sum;
				}
				
				//Move array back into position
				swap(array, i, i2);
			}
		}
	}

	std::cout << "Returning: " << minSum << std::endl;
	return minSum;
}

int main()
{
	const int arraySize = 6;
	int array[arraySize];
	array[0] = 8;
	array[1] = 4;
	array[2] = 5;
	array[3] = 3;
	array[4] = 2;
	array[5] = 7;

	std::cout << sillySort(array, arraySize) << std::endl;
	return 0;
}
