/*
* Made by Jin Min Chen for the Udemy course taught by Frank J. Mitropoulos
*/
#include <iostream>

using namespace std;

void print(const int const*, size_t);
int *apply_all(const int[], size_t, const int[], size_t);

int main()
{
	const size_t array1Size{ 5 };
	const size_t array2Size{ 3 };
	int array1[]{ 1,2,3,4,5 };
	int array2[]{ 10,20,30 };

	cout << "Array1: ";
	print(array1, array1Size);

	cout << "Array2: ";
	print(array2, array2Size);

	int *results = apply_all(array1, array1Size, array2, array2Size);
	cout << "Results: ";
	print(results, array1Size*array2Size);

	delete[] results;
	return 0;
}

void print(const int *ar, size_t length)
{
	cout << "[ ";
	for (size_t i{ 0 }; i < length; i++)
	{
		cout << ar[i] << " ";
	}
	cout << "]\n";
}

int *apply_all(const int ar1[], size_t length1, const int ar2[], size_t length2)
{
	int *tmp_ar = new int[length1*length2];
	int pos{ 0 };
	for (size_t j{ 0 }; j < length2; j++)
	{
		for (size_t i{ 0 }; i < length1; i++)
		{
			tmp_ar[pos++] = ar1[i] * ar2[j];
		}
	}
	return tmp_ar;
}