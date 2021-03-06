#include <iostream>
using namespace std;

#define INITIAL_SIZE 5

struct Node
{
    int data;
    Node *next;
};
Node *start = nullptr;

void print()
{
    Node *next = start;

    while ( next != nullptr) {
        cout<<next->data<<" ";
        next = next->next;
    }

    cout<<endl;
    return;

}

void insert_after(int position, int value)
{
    Node *after = start;
    Node *node;

    int i = 0;

    if(position == 0) {
        start = new Node;
        start->data = value;
        start->next = after;
    } else {
        while (i < position-1) {
            after = after->next;
            i++;
        }

        node = new Node;
        node->data = value;
        node->next = after->next;

        after->next = node;
    }

    print();
    return;

}

void delete_position(int position)
{
    Node *node = start;
    Node *temp;

    int i = 1;

    if(position == 1) {
        start = node->next;

    } else {
        while (i < position) {
            temp = node;
            node = node->next;
            i++;
        }
        temp->next = node->next;
    }
    delete node;
    print();
    return;
}

void insert_in_sorted_list(int value)
{
    int position = 0;

    Node *next = start;

    while ( next != nullptr && value >= next->data) {
        next = next->next;
        position++;
        if(next == nullptr || value < next->data) break;
    }

    insert_after(position, value);
    return;
}

void sort_list()
{
    Node *current = start;

    while ( current != nullptr ) {
        Node *next = current->next;
        while(next != nullptr) {
            if(current->data > next->data) {
                int temp = current->data;
                current->data = next->data;
                next->data = temp;
            }
            next = next->next;
        }
        current = current->next;
    }

    print();
    return;
}

void initialize()
{
    Node *node;
    start = node = new Node;
    for(int i=1; i<=INITIAL_SIZE; i++) {
        node->data = (i-6)*(i-6);
        if(i==INITIAL_SIZE) {
            node->next = nullptr;
        } else {
            node->next = new Node;
            node = node->next;
        }
    }
    print();
    return;
}

int main()
{
    print();
    initialize();

    insert_after(5, 36);
    delete_position(6);

    sort_list();
    insert_in_sorted_list(40);
    insert_in_sorted_list(12);
    insert_in_sorted_list(0);

    delete_position(1);

    cout<<endl;
    return 0;
}


/*

            Theories
        ================

Algorithm: Single Linked List

1. *** POINTER SUCKS ***
2. Specially object pointers.

*/
