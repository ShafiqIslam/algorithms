#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

#define CONFIDENCE .99
#define STOP_AT_MIN_CONFIDENCE true
#define MAX_ITERATION 10

long double probability_of_not, probability;

unsigned long long upower(unsigned a, unsigned b) {
    unsigned long long power = 1;
    if (a <= 1)
        return a;
    while (b-- > 0) {
        unsigned long long power_before = power;
        power *= a;
        if (power < power_before) {
          return 0;
        }
    }
    return power;
}

unsigned modular_exponent(unsigned a, unsigned b, unsigned m)
{
    unsigned c=1;
    for(unsigned i=1; i<=b; i++) {
        c = (a*c) % m;
    }
    return c;
}

bool is_prime(unsigned n)
{
    unsigned r;
    probability_of_not = 1.0;
    probability= 0.0;

    for (int i=1; i<=MAX_ITERATION; i++) {

        srand (time(NULL) + i);
        r = (rand() % (n-2)) + 2;

        /*
        unsigned long long exp = upower(r, n - 1);
        if(!exp) {
            continue;
        }
        if( (exp % n) != 1) {
            return false;
        }
        */

        // not calculating exponent then modulus
        // instead of use Modular Exponentiation Algorithm
        if( modular_exponent(r, n-1, n) != 1 )
            return false;


        probability_of_not = probability_of_not * 0.5;
        probability = 1 - probability_of_not;

        if( STOP_AT_MIN_CONFIDENCE && probability >= CONFIDENCE )
            return true;
    }
    return true;
}

int main ()
{
    cout << fixed;
    cout << setprecision(3);

    unsigned num;
    while(1) {
        cout<<"Enter a number(0 to stop): ";
        cin>>num;
        if(!num) break;

        cout<<num;
        if(is_prime(num)) {
            if(probability < CONFIDENCE) {
                cout<<" is found prime with probability of: "<<probability<<" and did't meet the given confidence level.";
            } else {
                cout<<" is probably a prime with probability of: "<<probability;
            }
        } else {
            cout<<" is not a prime.";
        }

        cout<<endl<<endl;
    }

    cout<<endl;
    return 0;
}




/*

                    Theories
                ================

Algorithm: Primality checking with Fermat Little Theorem

Fermat Little Theorem:
----------------------
If p is prime then for any n (2 <= n < p), then n^(p-1) == 1 mod p, or, n^(p-1) mod p = 1

Example:
p = 17, n = 2
n^(p-1) = 2^16 = 65536 == 1 mod 17 ( 65536 = 17 * 3855 + 1 )

So, to see if p is prime:
1. Pick a random number between 2 and p-1
2. Calculate n^(p-1) % p
3. If result is not 1, then p is not prime.


Now, sadly this theorem does not always give correct result.
n^(p-1) == 1 mod p is possible, though p is not prime.

So, a probabilistic approach is used.

In 1 test, chance of not prime = 1/2
and 2 test, chance of not prime = 1/2 * 1/2 = 1/4
So, in k test, chance of not prime = 1/(2^k)

Multiple test can be run until a confidence level is reached.
So, if the condition is not fulfilled then it's not prime,
otherwise test again to gain minimum confidence or, until a max test iteration.

Complexity: Using fast algorithms for modular exponentiation, the running time of this algorithm is
O(k * (log n)^2 * log(log n) * log( log( log n) ) ), where k is the number of iteration,
and n is the value we want to test for primality.


Modular Exponentiation:
-----------------------
*** ( (a mod p) (b mod p) ) mod p  =  (ab) mod p

The algorithm is as follows:
1. Set c = 1, e' = 0.
2. Increase e' by 1.
3. Set c = (b * c) mod m.
4. If e' < e, goto step 2. Else, c contains the correct solution to c be mod m.
Note that in every pass through step 3, the equation c = b^e' mod m holds true.
When step 3 has been executed e times, then, c contains the answer that was sought.
In summary, this algorithm basically counts up e' by ones until e' reaches e,
doing a multiply by b and the modulo operation each time it adds one (to ensure the results stay small).

*/
