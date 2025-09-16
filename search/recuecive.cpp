#include <iostream>
using namespace std;

// Recursive binary search function
// Returns the index of target if found, otherwise -1
int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1; // Not found
    }

    int mid = left + (right - left) / 2; // Avoid overflow

    if (arr[mid] == target) {
        return mid; // Found
    } 
    else if (arr[mid] < target) {
        return binarySearch(arr, mid + 1, right, target); 
    } 
    else {
        return binarySearch(arr, left, mid - 1, target); 
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
