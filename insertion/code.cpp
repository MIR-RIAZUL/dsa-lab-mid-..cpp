#include<iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        int current = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev]>current)
        {
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = current;
    }
}

int main()
{
    int n, m;

    int mm;
   

    cout<<"Enter the number of elements in the array: ";
    cin>>n;
     int array[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++)
    {
        cin>>array[i];
    }
    insertionSort(array, n);
    cout<<"Sorted array: "; 
    for(int i=0; i<n; i++)
    {
        cout<<array[i]<<" ";
    }
    return 0;
}
