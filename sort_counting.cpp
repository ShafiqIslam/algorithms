#include <iostream>
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

void count_sort(int *arr, int len, int min, int max)
{
    int range = max - min + 1;
    int* count_array = new int[range];

    int i, j;

    for(i=0; i<range; i++) {
        count_array[i] = 0;
    }

    for(i=0; i < len; i++) {
        int count_index = arr[i] - min;
        count_array[ count_index ]++;
    }

    j = 0;
    for(i=0; i<range; i++) {
        int freq = count_array[i];
        while(freq) {
            arr[j] = i + min;
            j++;
            freq--;
        }
    }

    return;
}

int main()
{
    int arr[7] = { 9, 2, 7, 1, 6, 8, 5 };
    int min = 1;
    int max = 9;
    int len = sizeof(arr)/sizeof(arr[0]);

    print(arr, len);
    cout<<endl<<endl;

    cout<<"Counting Sort:"<<endl;
    count_sort(arr, len, min, max);

    cout<<endl;
    print(arr, len);

    cout<<endl;
    return 0;
}


/*
                    Theories
              ====================

Algorithm: Counting Sort

1. Create a frequency array of size Range(from minimum to maximum) with value 0.
2. Count up the frequency of data items and generate the frequency array.
3. Rearrange the array based on the frequency.

This algorithm works faster than any other sorting algorithm if the range is known
and it is not terribly vast.

Runtime:
--------
1. For creating the array: O(r) or, O(1)
2. Counting frequencies: O(n)
3. Rearrange: O(r + n)
[n.b.: not O(r*n); because, the total frequency will be n.
And the inner loop will run n times in total regardless of the outer loop. ]

*** Complexity: O(r + n)

*/


