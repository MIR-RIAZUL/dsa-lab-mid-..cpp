#include <iostream>
using namespace std;

int inxx = 0;

void selection(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int smallestIndx = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[smallestIndx])
                smallestIndx = j;
        }
        if(smallestIndx != i) {  
            swap(arr[i], arr[smallestIndx]);
            inxx++;
        }
    }
}

int main()
{
    int n;
    cout << "Enter how many numbers in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the array: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    selection(arr, n);

    cout << "After the selection sort: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Number of swaps: " << inxx << endl;
}
