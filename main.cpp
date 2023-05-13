#include <fstream>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int getMax(long long arr[], long long n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void countSort(long long arr[], long long n, long long exp)
{
	// Count[i] array will be counting the number of array values having that 'i' digit at their (exp)th place.
	int output[n], i, count[10] = {0};

	// Count the number of times each digit occurred at (exp)th place in every input.
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Calculating their cumulative count.
	for (i = 1; i < 10; i++)
		count[i] += count[i-1];

	// Inserting values according to the digit '(arr[i] / exp) % 10' fetched into count[(arr[i] / exp) % 10].
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Assigning the result to the arr pointer of main().
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}
void radixsort(long long arr[], long long n)
{
	long long exp, m;
	m = getMax(arr, n);

	for (exp = 1; m/exp > 0; exp *= 10)
		countSort(arr, n, exp);
}
void heapify(long long int arr[], long long N, long long i)
{

    // Initialize largest as root
    long long largest = i;

    // left = 2*i + 1
    long long l = 2 * i + 1;

    // right = 2*i + 2
    long long r = 2 * i + 2;

    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

// Main function to do heap sort
void heapSort(long long arr[], long long N)
{

    // Build heap (rearrange array)
    for (long long i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // One by one extract an element
    // from heap
    for (long long i = N - 1; i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
int partition(long long* arr, long long start, long long end)
{
      // assuming last element as pivotElement
    int index = 0, pivotElement = arr[end], pivotIndex;
    int* temp = new int[end - start + 1]; // making an array whose size is equal to current partition range
    for (int i = start; i <= end; i++) // pushing all the elements in temp which are smaller than pivotElement
    {
        if(arr[i] < pivotElement)
        {
            temp[index] = arr[i];
            index++;
        }
    }

    temp[index] = pivotElement; // pushing pivotElement in temp
    index++;

    for (int i = start; i < end; i++) // pushing all the elements in temp which are greater than pivotElement
    {
        if(arr[i] > pivotElement)
        {
            temp[index] = arr[i];
            index++;
        }
    }
  // all the elements now in temp array are order :
  // leftmost elements are lesser than pivotElement and rightmost elements are greater than pivotElement



    index = 0;
    for (int i = start; i <= end; i++) // copying all the elements to original array i.e arr
    {
        if(arr[i] == pivotElement)
        {
              // for getting pivot index in the original array.
              // we need the pivotIndex value in the original and not in the temp array
            pivotIndex = i;
        }
        arr[i] = temp[index];
        index++;
    }
    return pivotIndex; // returning pivotIndex
}

void quickSort(long long* arr, long long start, long long end)
{
    if(start < end)
    {
        int partitionIndex = partition(arr, start, end); // for getting partition
        quickSort(arr, start, partitionIndex - 1); // sorting left side array
        quickSort(arr, partitionIndex + 1, end); // sorting right side array
    }
    return;
}
using namespace std;
bool isAscending(long long arr[], int size) {
    for (long long i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i+1]) {
            return false;
        }
    }
    return true;
}
void Merge(long long *a,long long low, long long high, long mid)
{
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}

	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}

void MergeSort(long long *a, long long low, long long high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
		Merge(a, low, high, mid);
	}
}
void bubbleSort(long long int arr[], long long int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
void insertionSort(long long arr[], long long n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void selectionSort(long long int*array, long long length);
int main() {
	long long int array[200000];

	srand(time(0));
    long long int k=2000000;
    for(long long int x = 0; x<k; x++)
    {array[x]=rand();
    }
    //sort(array, array + k, greater<int>());
    for (long long i = 0; i < k; ++i) {
			cout << array[i] << ' ';
		}
		countSort(array,0,k);
     /*if ( isAscending(array, k) ) {
        cout << "Array is ascending" << endl;
    } else {
        cout << "Array is not ascending" << endl;
    }*/
		return 0;
}
/*int main() {
    const long long int SIZE = 50;
    long long int array[SIZE];
    int n=0;
    ifstream inputFile("date.in");

    while (inputFile >> array[n] && n < SIZE) {
        n++;
    }

    inputFile.close();

    //MergeSort(array, 0,SIZE);
    countSort(array,0,SIZE);

    return 0;
}
void selectionSort(long long* array, long long int length) {
	for (int i=0; i<length-1; ++i) {
		int min = i;
		for (int j=i+1; j<length; ++j) {
			if (array[min]>array[j]) {
				min = j;
			}
		}
		if (i < min) {
			array[i]^=array[min]^=array[i]^=array[min];
		}
	}
}*/
