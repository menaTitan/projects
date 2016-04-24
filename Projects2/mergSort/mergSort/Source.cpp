#include <iostream>
using namespace std;

void merge(int arr[], int size, int low, int middle, int high) {
	//create temp array to hold the value
	int *temp;
	temp = new int[size];
	for (int i = low; i <= high; ++i) {
		temp[i] = arr[i];
	}
	int i = low;
	int j = middle + 1;
	int k = low;
	// if the value in the temp array is less than j value the place that value in the perment array
	while (i <= middle && j <= high) {
		if (temp[i] <= temp[j]) {
			arr[k] = temp[i];
			++i;
		}
		else {
			// take the j value and put it perment array
			arr[k] = temp[j];
			++j;
		}
		++k;
	}
	while (i <= middle) {
		//perment array value equal at the temporay array
		arr[k] = temp[i];
		++k;
		++i;
	}
	delete[] temp;
}

void merge_sort(int arr[], int size, int low, int high) {
	// check if low less than high
	if (low < high) {
		// find the middle value
		int middle = (low + high) / 2;
		//call merge_sort on the lower half of the array
		merge_sort(arr, size, low, middle);
		//call merge_sort on the upper half of the array
		merge_sort(arr, size, middle + 1, high);
		//marge it all together
		merge(arr, size, low, middle, high);
	}
}
void mergesort(int array[], int size){

	// call function that take more arrgument.
	merge_sort(array, size, 0, size - 1);
}
int main()
{
	const int size = 10;
	int numbers[] = { 5, 10, 1, 6, 2, 9, 0, 8, 7, 4 };
	mergesort(numbers, size);
	for (int i = 0; i < size; ++i) {
		cout << numbers[i] << " ";
	}
	return 0;
}
