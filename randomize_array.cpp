#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main ()
{
    int len = 9;
    int my_array[9] = {1,2,3,4,5,6,7,8,9};

    for(int i=len-1; i > 0; i--) {
        srand (time(NULL));
        int j = rand() % i;

        int t = my_array[i];
        my_array[i] = my_array[j];
        my_array[j] = t;
    }

    for(int i=0; i < 9 ; i++) {
        cout << my_array[i]<<" ";
    }
    cout<<endl;
    return 0;
}


/*
                    Theories
              ====================

Algorithm: Fisher–Yates shuffle / Knuth Shuffle


1. Pick a random number(or position) between current number position(exclusive) and the numbers remaining.
2. Swap picked number with current number.
3. Move to next position until all numbers have been struck out.

*/
