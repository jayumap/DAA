// Merge sort in C++

#include <iostream>
using namespace std;

// Merge two subarrays L and M into arr
void merge(int numbers[], int p, int q, int r) {
  
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = numbers[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = numbers[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      numbers[k] = L[i];
      i++;
    } else {
      numbers[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    numbers[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    numbers[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int numbers[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(numbers, l, m);
    mergeSort(numbers, m + 1, r);

    // Merge the sorted subarrays
    merge(numbers, l, m, r);
  }
}

// Print the array
void printArray(int numbers[], int n) {
  for (int i = 0; i < n; i++)
    cout << numbers[i] << " ";
  cout << endl;
}

// Driver program
int main() 
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    //accept numbers 
    cout<<"Enter the numbers in array: ";
    int numbers[n];
    for(int i=0; i<n; i++)
    {
        cin>>numbers[i];
    }
//   int arr[] = {6, 5, 12, 10, 9, 1};
//   int size = sizeof(arr) / sizeof(arr[0]);

  mergeSort(numbers, 0, n - 1);

  cout << "Sorted array: \n";
  printArray(numbers, n);
  return 0;
}