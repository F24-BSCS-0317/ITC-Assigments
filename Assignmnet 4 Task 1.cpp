#include<iostream>
using namespace std;
int main()
{
	// Declaration of the array, array size, total sum of the pairs

	int arr[100], size, sum = 0;  

	// Declaration of a boolean to check for duplicate elements

	bool dupli = false;         

	// Entering and Checking the size of the array to be greater than 10

	cout << "Enter the size of the array: ";
	cin >> size;
	while (size < 9)
	{

		// If statement to give error at size less than 0

		if (size < 0) 
			cout << "The size MUST be positive." << endl;

		cout << "Enter atleast 10 size: ";
		cin >> size;
	}
	// Loop to enter the elements in the array

	for (int i = 0; i < size; i++)
	{
		cout << "Enter Element " << i + 1 << ": ";
		cin >> arr[i];
	}cout << endl;

	cout << "The Elements in the array are: " << endl << endl;
	for (int i = 0; i < size; i++)  //  Outer loop to cycle the x elements
	{
		for (int j = 0; j < size; j++) //  Inner loop to cycle the y elements
		{
			if (j != i) //  No element of the same index to be repeated
			{
				if (arr[j] == arr[i]) // If statement to check for duplicates
				{
					dupli = true;
				}
				cout << "(" << arr[i] << "," << arr[j] << ")    ";
				sum += arr[i] + arr[j];  // Calculation of the sum of all pairs
			}
		}cout << endl;
	}cout << endl;

	// Loop Condition to print the subsets

	cout << "The Subsets in the array are: " << endl << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			cout << "(" << arr[i] << "," << arr[j] << ")    ";
		}
		cout << endl;
	}

	// Loop Condition to print the pairwise conparision

	cout << "The Pair Comparisions: " << endl << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i != j)
			{
				if (arr[i] > arr[j])
				{
					cout << "(" << arr[i] << ">" << arr[j] << ")    ";
				}
				else if (arr[i] < arr[j])
					cout << "(" << arr[i] << "<" << arr[j] << ")    ";
				else
					cout << "(" << arr[i] << "=" << arr[j] << ")    ";
			}
		}
		cout << endl;
	}cout << endl;

	// Patterns

	cout << "Patterns Found: " << endl << endl;

	// X > Y

	cout << "{In (x,y), x > y}: " << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i != j)
			{
				if (arr[i] > arr[j])
				{
					cout << "(" << arr[i] << "," << arr[j] << ")    ";
				}
			}
		}
		cout << endl;
	}cout << endl;

	// X < Y

	cout << "{In (x,y), x < y}: " << endl << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i != j)
			{
				if (arr[i] < arr[j])
				{
					cout << "(" << arr[i] << "," << arr[j] << ")    ";
				}
			}
		}
		cout << endl;
	}

	cout << endl << "The sum of all the pairs in the array is: " << sum << endl;
	if (dupli)
		cout << "There is a duplicate elemet in the array. " << endl;
	else
		cout << "There is no dulicate in the array. " << endl;
	return 0;
}