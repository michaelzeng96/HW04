#include <iostream>
using namespace std;


int main()
{
	cout << "How many numbers are in this array?" << endl;
	
	int iArraySize = 0;
	cin >> iArraySize;

	int * iArray = new int[iArraySize];

	cout << "Enter " << iArraySize << " numbers: ";

	int average = 0;
	int sum = 0;
	
	for (int i = 0; i < iArraySize; i++)
	{
		cin >> iArray[i];
		sum += iArray[i];
	}

	average = sum / iArraySize;

	cout << "The average is " << iArraySize << endl;

	int iNumbersAboveAvg = 0;
	for (int i = 0; i < iArraySize; i++)
	{
		if (iArray[i]>average)
			iNumbersAboveAvg++;
	}

	cout << "There are " << iNumbersAboveAvg << " numbers above average." << endl;

	return 0;
}