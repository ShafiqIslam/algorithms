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

void bubblesort(int *arr, int len)
{
    int i, j, swapped, c=1, downward=1, items_scanned;

    int last_swapped_bottom = len - 1;
    int last_swapped_up = 0;
    while(1) {
        swapped = 0;
        items_scanned = 0;

        if(downward) {
            // downward scan
            i = last_swapped_bottom;
            for(j=last_swapped_up; j<i; j++) {
                if(arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                    swapped = 1;
                    last_swapped_bottom = j;
                }
                items_scanned++;
            }
            downward = 0;
        } else {
            // upward scan
            i = last_swapped_up;
            for(j=last_swapped_bottom; j>i; j--) {
                if(arr[j] < arr[j-1]) {
                    swap(arr[j], arr[j-1]);
                    swapped = 1;
                    last_swapped_up = j;
                }
                items_scanned++;
            }
            downward = 1;
        }

        cout<<"Scan #"<<c++<<"  --  Items Scanned #"<<items_scanned<<endl;
        if(!swapped)
            return;

    }

    return;
}

int main()
{
    int arr[7] = { 1, 2, 7, 5, 6, 8, 9 };
    int len = sizeof(arr)/sizeof(arr[0]);

    print(arr, len);
    cout<<endl;

    cout<<"Bubble Sort:"<<endl;
    bubblesort(arr, len);

    cout<<endl;
    print(arr, len);

    cout<<endl;
    return 0;
}


/*
                    Theories
              ====================

Algorithm: Bubble Sort

1. Scan through the dataset and swap adjacent data if necessary.
2. Repeat for each item.
It takes n^2 steps.

This algorithm is very efficient when the dataset is almost sorted.
Because, there is no need to loop for n times.
If, once there was no swapping happened then, the loop can break.
So,
1. Scan through the dataset and swap adjacent data if necessary.
2. Repeat until no swapping happened.
It still takes n times to scan through the dataset, but total no of loops can be decreased,
if dataset is mostly sorted.
If not, then it still takes n^2 steps.


Some more modification can be applied:

1. Instead of always scanning from top. scanning from bottom can also help.
   E.g: 7 1 2 8
   here, only seven needs to be positioned,
   In the first scan 7 is swapped with 1 and then with 2.
   So, 7 is positioned only after one scan. Because, it was on the top.
   Now, if 1 were at the bottom, it would take 4 step to take that in position.
   But, if scanning was from bottom it would take only 1 step.
   So, if the scan happens from both direction the no. of scan can be reduced.

2. Keep track of the last sorted/swapped item. Below that (or, above that,
   depending on the scanning direction), there is no need to check further.
   This reduce the no of item in each scan to loop through.


*** Complexity: O(n^2)

*/


