#include <iostream>
#include <algorithm>
using namespace std;

void print(int *a, int n)
{
    int i = 0;
    while(i < n){
        cout << a[i] << " ";
        i++;
    }
    cout << "\n";
}

int partition(int *arr, int left, int right) {
    int mid = (right + left) / 2;

    int pivot = arr[mid];
    // move the mid point value to the front.
    swap(arr[mid], arr[left]);
    int i = left + 1;
    int j = right;
    while (i <= j) {
        while(i <= j && arr[i] <= pivot) {
            i++;
        }

        while(i <= j && arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i - 1], arr[left]);
    return i - 1;
}

void quicksort(int *arr, int left, int right, int sz){

    if (left >= right) {
        return;
    }


    int part = partition(arr, left, right);
    cout << "QSC:" << left << "," << right << " part=" << part << "\n";
    print(arr, sz);
    cout<<endl;

    quicksort(arr, left, part - 1, sz);
    quicksort(arr, part + 1, right, sz);

    return;
}

int main() {
    int arr[7] = { 7, 9, 3, 4, 8, 2, 1};
    int len = sizeof(arr)/sizeof(arr[0]);
    print(arr, len);
    cout<<endl;

    quicksort(arr, 0, len - 1, len);

    print(arr, len);

    cout<<endl;
    return 0;
}


/*

                    Theories
                =================

Algorithm: Quick Sort


1. find a 'pivot value'.
2. move all values less than (or equal to) the pivot value to 'the left'.
3. move all values larger than the pivot to 'the right'.
4. quick-sort the values less than(or equal)
5. quick-sort the values larger than.

Complexity:
-----------
Worst-Case:        O(n^2)
Average-Case:      O(n log n)
Best Case:         O(n log n)
Worst-Case Memory: O(n) when Naive else O(log n)


*** N.B.: ***
-------------
The mid calculation should be: mid = left + (right - left) / 2; not just mid = (left + right) / 2
Where the sum overflows to a negative value, and the value stays negative when divided by two.
The solution is mathematically same, but removes the programmatic error occurrence of overflow.
https://research.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html


*/
