#include <iostream>
using namespace std;

int * doubleCapacity(const int* list, int size)
{
	int* pNewList = new int[2 * size]; 
	for (int i = 0; i < size; i++)
	{
		pNewList[i] = list[i];
	}
	return pNewList;
}

int main()
{
	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; //test

	int *pdoublearray = doubleCapacity(array, 10);

	for (int i = 0; i < 10; i++)
	{
		cout << pdoublearray[i] << " ";
	}
	
	delete[] pdoublearray;

	return 0;
}