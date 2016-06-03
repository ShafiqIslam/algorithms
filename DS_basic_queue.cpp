#include <iostream>
using namespace std;

class Queue
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node *prev;
    };
    Node *start, *bottom;

public:
    Queue()
    {
        start = nullptr;
        bottom = nullptr;
    }

    void push(int value)
    {
        Node *new_node;
        new_node = new Node;
        new_node->data = value;
        new_node->next = nullptr;

        if(start != nullptr) {
            new_node->prev = bottom;
            new_node->prev->next = new_node;
        } else {
            new_node->prev = nullptr;
            start = new_node;
        }

        bottom = new_node;

        return;
    }

    int pop()
    {
        Node *node = start;
        start = node->next;
        start->prev = nullptr;

        int value = node->data;
        delete node;
        return value;
    }

    void print()
    {
        Node *next = start;

        cout<<"Current Queue: ";
        while ( next != nullptr) {
            cout<<next->data<<" ";
            next = next->next;
        }

        cout<<endl<<endl;
        return;

    }
};

int main()
{
    Queue my_queue;

    for(int i=1; i<=3; i++) {
        my_queue.push(i);
        cout<<"Pushed "<<i<<endl;
        my_queue.print();
    }

    for(int i=1; i<=2; i++) {
        my_queue.pop();
        cout<<"Popped "<<i<<endl;
        my_queue.print();
    }

    cout<<endl;
    return 0;

}


/*

            Theories
        ================

Data Structure: Basic Queue


Queue is a dataset, where only insertion is allowed from back,
and deletion from front.
So, it is termed as First In First Out (FIFO).

A doubly linked list is maintained for the queue.


*/
