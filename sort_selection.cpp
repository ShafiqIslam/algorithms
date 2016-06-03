#include <iostream>
using namespace std;

int main()
{
    int len = 5;
    int arr[5] = {5,4,2,1,3};
    int p,i;

    cout<<"Before Sort:"<<endl;
    for(i=0; i<len; i++) {
        cout<<arr[i]<<" ";
    }

    for(p=0; p<len; p++) {
        for(i=p+1; i<len; i++) {
            if( arr[i] < arr[p] ) {
                int t = arr[p];
                arr[p] = arr[i];
                arr[i] = t;
            }
        }
    }

    cout<<"\n\Selection Sort:"<<endl;
    for(i=0; i<len; i++) {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    return 0;
}


/*
                    Theories
              ====================

Algorithm: Selection Sort

The Basic:
----------
Select the correct value for position p and assign it that position.
Steps needed: n + n + n + ...... + n (up-to n) = n^2 = O(n^2)

Here, In-Place Selection Sort is used. Which takes the value of position p and swaps it
with the correct value. Then move on with the remaining positions.
Steps needed: n + (n-1) + (n-2) + ...... + 1 = n(n+1) / 2 = O(n^2)

*** Complexity: O(n^2) [every case]

*/


