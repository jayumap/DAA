#include<iostream>
using namespace std;

 
int partition(int numbers[], int start, int end)
{
 
    int pivot = numbers[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (numbers[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(numbers[pivotIndex], numbers[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (numbers[i] <= pivot) {
            i++;
        }
 
        while (numbers[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) 
        {
            numbers[numbers[i++], numbers[j--]];
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int numbers[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(numbers, start, end);
 
    // Sorting the left part
    quickSort(numbers, start, p - 1);
 
    // Sorting the right part
    quickSort(numbers, p + 1, end);
}

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

    //print accepted array
    cout<<"\nAccepted array is: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<numbers[i]<<" ";
    }

    //output after quicksort opn
    cout<<"\nArray after quick sort operation:";
    quickSort(numbers, 0, n - 1);
 
    for (int i =0; i<n; i++) {
        cout << numbers[i] << " ";
    }
 


}