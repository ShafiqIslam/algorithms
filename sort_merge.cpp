#include <iostream>
using namespace std;

void print(int *a, int n)
{
    int i = 0;
    while(i < n){
        cout << a[i] << " ";
        i++;
    }
    cout << endl;
}

void merge(int *a, int low, int high, int mid, int len)
{
    int i, j, k;
    int* sub_sorted_array = new int[len];

    i = low;
    k = low;
    j = mid + 1;

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            sub_sorted_array[k] = a[i];
            i++;
        } else {
            sub_sorted_array[k] = a[j];
            j++;
        }
        k++;
    }

    //  if any elements remain in the arrays
    while (i <= mid) {
        sub_sorted_array[k] = a[i];
        k++;
        i++;
    }
    while (j <= high) {
        sub_sorted_array[k] = a[j];
        k++;
        j++;
    }

    for (i = low; i < k; i++) {
        a[i] = sub_sorted_array[i];
    }
}

void mergesort(int *a, int low, int high, int len)
{
    int mid;
    if (low < high) {
        mid = (low+high)/2;
        mergesort(a, low, mid, len);
        mergesort(a, mid+1, high, len);
        merge(a, low, high, mid, len);
    }
    return;
}

int main()
{
    int arr[7] = { 7, 9, 3, 4, 8, 2, 1};
    int len = sizeof(arr)/sizeof(arr[0]);
    print(arr, len);
    cout<<endl;

    mergesort(arr, 0, len - 1, len);
    print(arr, len);

    cout<<endl;
    return 0;
}


/*


                    Theories
                ===============

Algorithm: Merge Sort
=====================

The basic idea is simple.
1. Recursively divide the items in two similar size sets until there is one element.
2. Merge the sorted items from bottom to up.

The division is simple:
                        m(0, 3)
                      /        \
                     /          \
                    /            \
               m(0, 1)         m(2, 3)
              /       \        /      \
             /         \      /        \
       m(0, 0)     m(1, 1) m(2, 2)     m(3, 3)

The merging of two set works like:
1)  3 4 7 9     1 2 6 8     =>  sub sorted array: 1
    -           -

2)  3 4 7 9     1 2 6 8     =>  sub sorted array: 1 2
    -             -

3)  3 4 7 9     1 2 6 8     =>  sub sorted array: 1 2 3
    -               -

4)  3 4 7 9     1 2 6 8     =>  sub sorted array: 1 2 3 4
      -             -

and so on, until two set are fully sorted.



Complexity: O (n log n)
=======================

It takes n steps to merge n elements. And in every level there is n elements present and n elements are copied to
new array. So it is order n.
And there is log(n) levels for n no. of data item.

So, total complexity will be n log(n).
This is for each and every situation.
No matter of the arrangement of initial dataset.

Where, quick sort performs terrible when the initial dataset are mostly sorted or contain duplicate values.
So, unlike quick sort, merge sort always performs at n*log(n) complexity.

*/
