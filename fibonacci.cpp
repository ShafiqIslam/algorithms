#include <iostream>
using namespace std;

unsigned long long int fibonacci_normal_recursion(unsigned long long int n)
{
    if(n <= 1)
        return 1;

    return fibonacci_normal_recursion(n-1) + fibonacci_normal_recursion(n-2);
}

unsigned long long int f[1000];
void fibo_init(unsigned long long int n)
{
    f[0] = 1;
    f[1] = 1;
    for(int i=2; i<=n; i++) {
        f[i] = 0;
    }
}
unsigned long long int fibonacci_fixed_recursion(unsigned long long int n)
{
    if( f[n] == 0 ) {
        f[n] = fibonacci_fixed_recursion(n-1) + fibonacci_fixed_recursion(n-2);
    }

    return f[n];
}

unsigned long long int fibonacci_bottom_up(unsigned long long int n)
{
    if( n <= 1 )
        return 1;

    unsigned long long int f_n_minus_1 = 1, f_n_minus_2 = 1, f_n, i;

    for(i=2; i<=n; i++) {
        f_n = f_n_minus_1 + f_n_minus_2;
        f_n_minus_1 = f_n_minus_2;
        f_n_minus_2 = f_n;
    }

    return f_n;
}

int main()
{
    unsigned long long int n = 30;
    cout<<"Normal Recursive Method"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"No. "<<n<<" Fibonacci number is = "<<fibonacci_normal_recursion(n);
    // this took 163.989s for n = 50

    cout<<endl<<endl<<endl;

    n = 4;
    fibo_init(n);
    cout<<"Fixed Recursive Method"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"No. "<<n<<" Fibonacci number is = "<<fibonacci_fixed_recursion(n);
    // this took 0.011s for n = 50; 0.012 s for n = 80

    cout<<endl<<endl<<endl;

    n = 80;
    cout<<"Bottom Up Method"<<endl;
    cout<<"----------------"<<endl;
    cout<<"No. "<<n<<" Fibonacci number is = "<<fibonacci_bottom_up(n);
    // this also took 0.012s for n = 80

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


*** Fixing Recursion ***
========================

1.
The previous algorithm does a lot of duplicate calculation again and again.
ex:
                                Fibonacci(6)
                Fibonacci(5)                   Fibonacci(4)
        Fibonacci(4)  Fibonacci(3)        Fibonacci(3)  Fibonacci(2)

The whole right branch is unnecessary, because Fibonacci(4) is already calculated while traversing left branch.
So, if the previously calculated values are stored then it would be much more efficient.

Complexity: O(n)


2.
Also a bottom up approach can be followed.
To calculate the values from beginning and add up manually.
This also has complexity O(n).


*/
