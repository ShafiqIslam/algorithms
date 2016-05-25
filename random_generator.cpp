#include <iostream>
using namespace std;

unsigned int rseed = 0;

#define RAND_MAX 2147483647
#define A 1103515245
#define B 12345

inline void srand(int x)
{
	rseed = x;
}

int rand()
{
    return rseed = (rseed * A + B) % RAND_MAX;
}

int rand(int m)
{
    return rseed = (rseed * A + B) % m;
}

int main()
{
    for (int i = 0; i < 10; i++)
		cout<<rand()<<endl;

    cout<<endl;
    return 0;
}



/*
                    Theories
              ====================

Algorithm: LCG - Linear Congruential Generator (Pseudo Random number generator)

*** X(n+1) = { X(n) * A + B } (mod M)



Conditions of Full Period:
--------------------------
1. B and M are relatively prime (no common factors).
2. (A-1) must be divisible by all prime factors of M.
3. (A-1) must be multiple of 4 if M is.


*/
