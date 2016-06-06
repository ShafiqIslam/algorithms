#include <iostream>
using namespace std;

int index_of(int search_item, int *a, int len)
{
    int low = 0;
    int high = len-1;
    int mid;

    while(low <= high) {
        mid = (low+high) / 2;
        if(a[mid] == search_item) {
            return mid;
        } else if(search_item < a[mid]) {
            high = mid-1;
        } else if(search_item > a[mid]) {
            low = mid+1;
        }
    }

    return -1;
}

void insertion_sort(int *arr, int len)
{
    int i, j, key;

    for(j=1; j<len; j++) {
        key = arr[j];
        for(i=j-1; i>=0 && arr[i] > key; i--) {
            arr[i+1] = arr[i];
        }
        arr[i+1] = key;
    }

    return;
}

int main()
{
    int arr[7] = { 9, 2, 7, 1, 6, 8, 5 };
    int search_for = 10;
    int len = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr, len);

    int i = index_of(search_for, arr, len);
    if( i >= 0 ) {
        cout << "Item found on index: " << i;
    } else {
        cout << "Item could not be found.";
    }

    cout<<endl;
    return 0;
}


/*
                    Theories
              ====================

Algorithm: Binary Search


Binary search works on sorted arrays. A binary search begins by comparing the middle element of
the array with the target value. If the target value matches the middle element, its position in the array is returned.
If the target value is less or more than the middle element, the search continues the lower or
upper half of the array respectively with a new middle element, eliminating the other half from consideration.


*** Complexity: O(log n); for searching only.

*/


