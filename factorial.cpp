#include <iostream>
using namespace std;

int factorial(int n)
{
    if(n == 1)
        return 1;

    return n * factorial(n-1);
}

int main()
{
    int n = 5;
    cout<<n<<"! = "<<factorial(n);
    cout<<endl;
    return 0;
}


/*
            Theories
        ===============

Algorithm: Basic Recursion

***Complexity: O(n)

*/
