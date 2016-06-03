#include <iostream>
using namespace std;

void print(int *a, int n)
{
    for (int i=0; i<n; ++i)
        cout << a[i] << " ";

    cout<<endl;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)

    //last root node is in n/2 -1 index.
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--) {
        // Move current root to end then heapify reduced array
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {9, 4, 1, 5, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Heap Sorted: ";
    print(arr, n);

    cout<<endl;
    return 0;
}


/*

                    Theories
                ================

Algorithm: Heap Sort


1. Build a max heap.
2. At this point, the largest item is stored at the root of the heap.
   Replace it with the last item of the heap followed by reducing the size of heap by 1.
   Finally, heapify the root of tree.
3. Repeat above steps until heap is empty.


Since a Binary Heap is a Complete Binary Tree, it can be easily represented as array and
array based representation is space efficient.
If the parent node is stored at index p,
the left child can be calculated by 2p + 1 and right child by 2p + 2.
and, If the children node is stored at index c,
then its parent index will be (c-1)/2.

Complexity: O( n log n )


*/
