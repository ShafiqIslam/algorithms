#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if(a==b)
        return a;

    int max = (b>a) ? b : a;
    int min = (b<a) ? b : a;

    if(min == 0)
        return max;

    int mod = max % min;

    return gcd(min, mod);

}

int lcm(int a, int b)
{
    return ( a / gcd(a, b) ) * b;
}

int main ()
{
    int num_1 = 66, num_2 = 78;
    cout<<"GCD(" << num_1 << ", " << num_2 <<") = "<<gcd(num_1, num_2)<<endl;
    cout<<"LCM(" << num_1 << ", " << num_2 <<") = "<<lcm(num_1, num_2)<<endl;

    cout<<endl;
    return 0;
}


/*
                    Theories
              ====================

Algorithm: Euclidean Algorithm for Greatest Common Divisor and Least Common Multiple

1. gcd(A,B) = gcd(B, A%B), until A % B = 0
Background:
While A%B (=R),
    A = c * B + R
Now, A and B both are divisible by gcd, => R must have to be divisible by gcd.
So, gcd(A,B) = gcd(A,R) = gcd(B,R)

Because, switching the values with remainder does not remove the gcd.
The remainder always contains the gcd as a factor until the remainder is 0.
And, the remainder will must be zero at some point even for prime numbers.
Because, eventually they will always both be multiples of 1.



2. gcd(A,B) * lcm(A,B) = A * B


*** Complexity : O(log n)


*/


