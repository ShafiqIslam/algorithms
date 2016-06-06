#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if(n == 1 || n == 0)
        return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n = 13;
    cout<<"No. "<<n<<" Fibonacci number is = "<<fibonacci(n);
    cout<<endl;
    return 0;
}


/*
            Theories
        ===============

Algorithm: Recursively find Fibonacci Numbers

***Complexity: O( Fibonacci(n) )

As, the call stack will like a binary tree, but that is not a complete tree,
so, the number of root or leaf nodes can not be simplified.
(If it was binary tree, then it would be 2^n)

So, For this algorithm there is no simplified runtime complexity.
Instead, let it would take T(n) time to compute F(n).
so, T(n-1) for calculating F(n-1) and T(n-2) to compute F(n-2)

So, from the recursive function,
T(n) = T(n-1) + T(n-2)
and, that is the Fibonacci function itself.

So, runtime for this algorithm is = O( Fibonacci(n) )

*/
