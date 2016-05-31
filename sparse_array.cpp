#include <iostream>
using namespace std;

class SparseArray
{
private:
    struct ColumnNode
    {
        int column_number;
        ColumnNode *next_column;
        int data;
    };

    struct RowNode
    {
        int row_number;
        RowNode *next_row;
        ColumnNode *top_column;
    };
    RowNode* row_start;
    int default_value;

public:
    SparseArray()
    {
        default_value = 0;
        row_start = nullptr;
    }

    void setItem(int row, int column, int value)
    {
        if(value != default_value) {
            if(row_start == nullptr) {
                row_start = new RowNode;
                row_start->row_number = row;
                row_start->next_row = nullptr;
                row_start->top_column = new ColumnNode;
                row_start->top_column->data = value;
                row_start->top_column->column_number = column;
                row_start->top_column->next_column = nullptr;
            } else {
                RowNode *next_row = row_start;
                bool create_row = true;
                while ( next_row != nullptr) {
                    if(next_row->row_number == row) {
                        create_row = false;
                        break;
                    }

                    if(next_row->next_row != nullptr)
                        next_row = next_row->next_row;
                    else
                        break;
                }

                if(create_row) {
                    next_row->next_row = new RowNode;
                    next_row->next_row->next_row = nullptr;
                    next_row->next_row->row_number = row;
                    next_row->next_row->top_column = nullptr;
                    next_row = next_row->next_row;
                }

                ColumnNode *next_column = next_row->top_column;
                next_row->top_column = new ColumnNode;
                next_row->top_column->column_number = column;
                next_row->top_column->data = value;
                next_row->top_column->next_column = next_column;
            }

        }
        return;
    }

    int getItem(int row, int column)
    {
        RowNode *next_row = row_start;
        while ( next_row != nullptr) {
            if(next_row->row_number == row) {
                ColumnNode *next_column = next_row->top_column;
                while ( next_column != nullptr) {
                    if(next_column->column_number == column) {
                        return next_column->data;
                    }

                    next_column = next_column->next_column;
                }

                return default_value;
            }

            next_row = next_row->next_row;
        }

        return default_value;
    }
};

int main()
{
    int N = 8;
    int fligts[8][8] = {
        { 0, 0, 0, 1, 0, 0, 1, 0 },
        { 0, 0, 1, 1, 0, 0, 0, 1 },
        { 0, 1, 0, 0, 0, 1, 0, 0 },
        { 1, 1, 0, 0, 0, 1, 1, 0 },
        { 0, 0, 0, 0, 0, 1, 1, 0 },
        { 0, 0, 1, 1, 1, 0, 0, 1 },
        { 1, 0, 0, 1, 1, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 1, 0, 0 }
    };

    SparseArray my_array;
    for(int row = 0; row<N; row++) {
        for(int column =0; column<N; column++) {
            my_array.setItem(row, column, fligts[row][column]);
        }
    }

    cout<<my_array.getItem(3, 0);

    cout<<endl;
    return 0;
}



/*

                    Theories
                ================

Data Structure: Sparse Array

In a dataset, where there is a lot of unnecessary data or, default data,
there a sparse array can be used to save memory.

Sparse Array basically is a linked list of linked list, where primary nodes represent the rows,
and holds the secondary list, which represent the columns and holds the value.

Its structure is like 2-D arrays, but it can contain only the necessary data.
Default data can be omitted as they never exist in the list.

1. Row node holds the pointer to next row and the pointer to top column node.
2. Column node holds the data and pointer to next column node.
3. A row number tag and column number tag can be used to keep track of the position of the data cell.
4. If row and column not found, then it can be presumed that the position contains the default value;

This is another technique of Space-Time TradeOff.


*/

