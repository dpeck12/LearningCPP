#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <regex>
#include <iterator>
#include <unordered_set>
#include <cmath>
#include <queue>

using namespace std;

// Rotate ascending order sorted array at some pivot,
// pivot is unknown to you beforehand 

// Standard binary search function 
int binarySearch(int arr[], int low, int high, int key) {
    if (high < low)
        return -1;
    
    int mid = (low + high) / 2;
    if (key == arr[mid])
        return mid;
    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);
    
    return binarySearch(arr, low, (mid - 1), key);
}

// Function to get pivot 
// for array 3, 4, 5, 6, 1, 2
// returns 3 (index of 6)
int findPivot(int arr[], int low, int high) {
    // base cases 
    if (high < low)return -1; // Didn't find a pivot 
    if (high == low)return low;

    int mid = (low + high) / 2; // middle index
    //middle index < high index 
    // and middle element>middle+1 element
    if (mid<high && arr[mid]>arr[mid + 1]) 
        return mid;
    // If middle index > lowest index
    // middle element is less than previous element 
    if (mid > low && arr[mid] < arr[mid - 1])
        return(mid - 1);
    // if low element > middle element
    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);
    return findPivot(arr, mid + 1, high);
}
// Searches an element key in a pivoted
// sorted array arr[] of size n 
int pivotedBinarySearch(int arr[], int n, int key) {
    int pivot = findPivot(arr, 0, n - 1);

    // If we didn't find a pivot 
    //then array is not rotated at all
    if (pivot == -1)
        return binarySearch(arr, 0, n - 1, key);

    // If found pivot, then first compare with pivot 
    // then search in two subarrays around pivot 
    if (arr[pivot] == key)
        return pivot;

    if (arr[0] <= key)
        return binarySearch(arr, 0, pivot - 1, key);

    return binarySearch(arr, pivot + 1, n - 1, key);
}


int main()
{
    int arr1[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int key = 3;

    // Function calling 
    std::cout << "Index of the element is: " << pivotedBinarySearch(arr1, n, key);

    return 0;
}