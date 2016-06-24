#include <iostream>
#include <string>
using namespace std;

bool found = false;
struct Node
{
    string data;
    Node *left;
    Node *right;
};
Node *root;

void initialize()
{
    // root node
    root = new Node;

    // first level nodes
    root->left = new Node;
    root->right = new Node;
    root->data = "Bad";

    // second level nodes for first left node
    root->left->left = new Node;
    root->left->right = new Node;
    root->left->data = "Bad";

    // third level nodes (leaf nodes)
    root->left->left->left = nullptr;
    root->left->left->right = nullptr;
    root->left->left->data = "Bad";

    root->left->right->left = nullptr;
    root->left->right->right = nullptr;
    root->left->right->data = "Bad";


    // second level nodes for first right node
    root->right->left = new Node;
    root->right->right = new Node;
    root->right->data = "Bad";

    // third level nodes (leaf nodes)
    root->right->left->left = nullptr;
    root->right->left->right = nullptr;
    root->right->left->data = "Bad";

    root->right->right->left = nullptr;
    root->right->right->right = nullptr;
    root->right->right->data = "Bad";

    return;
}

bool search(Node *node)
{
    if(node->data == "Good") {
        found = true;
    }

    if(node->left != nullptr && !found)
        search(node->left);
    if(node->right != nullptr && !found)
        search(node->right);

    if(found) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    initialize();

    if(search(root))
        cout<<"Good leaf found.";
    else
        cout<<"No Good leaf found.";

    cout<<endl;
    return 0;
}



/*
            Theories
        ===============

Algorithm: Basic Backtracking

1. Search for a good leaf node.
2. If found then break, if not found then backtrack to previous branch.

*/
