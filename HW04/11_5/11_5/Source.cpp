#include <iostream>
using namespace std;

int iFindSmallest(int* list, int listsize);

int main()
{
	int list[] = { 1, 2, 4, 5, 10, 100, 2, -22 };

	cout << iFindSmallest(list, 8);

	return 0;
}

int iFindSmallest(int* list, int listsize)
{
	int i = 0;
	for (; i < listsize; i++)
	{
		for (int j = i + 1; j < listsize; j++)
		{
			if (list[j] < list[i])
			{
				int swap = list[j];
				list[j] = list[i];
				list[i] = swap;
			}
		}
	}
	i = 0;
	return list[i];
}