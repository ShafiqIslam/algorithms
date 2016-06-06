#include <iostream>
using namespace std;

int index_of(int search_item, int *a, int len)
{
    for(int i=0; i<len; i++) {
        if(a[i] == search_item) {
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr[7] = { 9, 2, 7, 1, 6, 8, 5 };
    int search_for = 1;

    int len = sizeof(arr)/sizeof(arr[0]);

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

Algorithm: Linear Search

*** Complexity: O(n); average: O(n/2)

*/


