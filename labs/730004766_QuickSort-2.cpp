#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

// Complete the function to swap two elements
void swap(int* a, int* b)
{
	//YOUR CODE HERE
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition (int arr[], int low, int high)
{
	int random = low + (rand() % (high-low));
  swap(arr[random], arr[high]);

	int pivot = arr[high];	//random pivot
	int i = (low - 1); // Index of smaller element

	for(int j= low; j<high; j++){
		if (arr[j] < pivot){	//less than or equal to pivot
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	//YOUR CODE HERE
	if(low < high){
		int pivot = partition(arr, low, high);
		quickSort(arr, low, pivot-1);
		quickSort(arr, pivot+1, high);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver Code
int main()
{
	srand(time(NULL));
	int size = rand() % 10 + 1;
	int arr[size];
	for( int i = 0; i < size; ++i ) {
    	arr[i] = rand() % 19 + (-9);
	}

	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Input array\n";
    printArray(arr, n);

	quickSort(arr, 0, n - 1);

	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}
