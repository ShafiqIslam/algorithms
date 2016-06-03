#include <iostream>
using namespace std;

class Stack
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *start;

public:
    Stack()
    {
        start = nullptr;
    }

    void push(int value)
    {
        Node *next = start;
        start = new Node;
        start->data = value;
        start->next = next;
        return;
    }

    int pop()
    {
        Node *node = start;
        start = node->next;
        int value = node->data;
        delete node;
        return value;
    }

    void print()
    {
        Node *next = start;

        cout<<"Current Stack: ";
        while ( next != nullptr) {
            cout<<next->data<<" ";
            next = next->next;
        }

        cout<<endl<<endl;
        return;

    }
};

int* reverse_array(int my_array[], int array_size)
{
    Stack reverse_array_stack;

    for(int i=0; i<array_size; i++) {
        reverse_array_stack.push(my_array[i]);
    }

    int* reverse_array = new int[array_size];

    for(int i=0; i<array_size; i++) {
        reverse_array[i] = reverse_array_stack.pop();
    }

    return reverse_array;

}

void print_array(int a[], int len)
{
    for(int i=0; i<len; i++)
        cout << a[i] << " ";

    return;
}


int main()
{
    /*
    Stack my_stack;

    for(int i=1; i<=3; i++) {
        my_stack.push(i);
        cout<<"Pushed "<<i<<endl;
        my_stack.print();
    }

    for(int i=1; i<=2; i++) {
        my_stack.pop();
        cout<<"Popped "<<i<<endl;
        my_stack.print();
    }
    */

    int array_size = 9;
    int* my_array = new int[array_size];
    int* reversed_array = new int[array_size];

    for(int i=0; i<array_size; i++)
        my_array[i] = i+1;

    reversed_array = reverse_array(my_array, array_size);

    cout<<"Original Array: ";
    print_array(my_array, array_size);

    cout<<endl<<endl<<"Reversed Array: ";
    print_array(reversed_array, array_size);

    cout<<endl;
    return 0;

}


/*

            Theories
        ================

Data Structure: Basic Stack


Stack is a dataset, where only first element can be accessed.
So, it is termed as Last In First Out (LIFO).


Implementation:
---------------
A simple array reversing is implemented via stack.
Array is pushed in a stack from first to last.
So, when popped, the values come in reversed order.

A list is maintained for the stack.


*/
