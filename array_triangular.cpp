#include <iostream>
using namespace std;

class TriangularArray
{
private:
    int num_rows;
    int storage_size;
    int* storage_array;

    int mapRowAndColumn (int row, int col)
    {
        int index;
        if(col > row) {
            int t = col;
            col = row;
            row = t;
        }
        index = ( row * (row-1) ) / 2 + col;
        return index;
    }

public:
    TriangularArray(int N)
    {
        storage_size = ( N * (N-1) ) / 2;
        storage_array = new int[storage_size];
        int i;
        for(i=0; i<storage_size; i++)
            storage_array[i] = 0;
    }

    void setValue(int row, int column, int value)
    {
        int index = mapRowAndColumn (row, column);
        storage_array[index] = value;
    }

    int getValue(int row, int column)
    {
        int index = mapRowAndColumn (row, column);
        return storage_array[index];
    }
};

/*

//
// functional approach
// ===================
//

int storage_size;
int storage_array[1000];

void print()
{
    for(int i=0; i<storage_size; i++) {
        cout<<storage_array[i]<<" ";
    }

    cout<<endl;
    return;
}

void make_triangular(int a[4][4], int N)
{
    storage_size = ( N * (N-1) ) / 2;
    int i;
    for(i=0; i<storage_size; i++)
        storage_array[i] = 0;

    int row=0, col=0, index;
    for(row=0; row<N && index<storage_size; row++) {
        for(col=0; col<N && index<storage_size; col++) {
            if(col > row) {
                int r = col;
                int c = row;
                index = ( r * (r-1) ) / 2 + c;
                storage_array[index] = a[r][c];
            }
        }
    }

    print();
    return;
}
*/

int main()
{
    int N = 4;
    int distances[4][4] = {
        {   0, 123, 256, 809 },
        { 123,   0, 754, 390 },
        { 256, 754,   0, 991 },
        { 809, 390, 991,   0 }
    };
    //make_triangular(distances, N);

    TriangularArray my_array(N);
    for(int r=0; r<N; r++) {
        for(int c=0; c<N; c++) {
            my_array.setValue(r,c, distances[r][c]);
        }
    }
    // go for row 3[2], column 4[3] : that is 991
    cout<<my_array.getValue(2,3);

    cout<<endl;
    return 0;
}


/*

            Theories
        ================

Suppose, some distance matrix like:
{   0, 123, 256, 809 }
{ 123,   0, 754, 390 }
{ 256, 754,   0, 991 }
{ 809, 390, 991,   0 }

Dataset like this can be saved in a 1d array instead of 2d.
Because of, repetition one data can be saved only once. And, the
diagonal elements can also be removed.

So, the ultimate dataset is
{ }
{ 123 }
{ 256, 754 }
{ 809, 390, 991 }

Now, this can be placed in a single array. which size is only 6 instead of 16.
The size = 0 + 1 + 2 + ...... + ( N-1 ) = N(N-1)/2

The indexing:
-------------
1. If Row < Column, then switch them. No need of those elements.
2. Index = 0 + 1 + 2 + .... + (Row - 1) + Column = Row(Row-1)/2 + Column

This technique is more time costly than normal 2D array implementation.
But it surely is more memory efficient. This type technique is called
Space-Time TradeOff.
--------------------


*/
