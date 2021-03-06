#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define ALGORITHM 1

vector<bool> prime;

void SieveOfEratosthenes(int n)
{
    prime.assign(n+1, true);  // because assignment starts with index 0

    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
}

bool is_prime(int a)
{
    if(a <= 2) {
        return true;
    } else {
        for(int i=2; i<=sqrt(a); i++) {
            if(a%i==0) {
                return false;
            }
        }
        return true;
    }
}

vector<int> prime_factorization_with_prime_numbers(int a)
{
    // generate prime number flags up-to the given number, instead check prime on every iteration
    SieveOfEratosthenes(a);

    vector<int> factors;

    for(int i=2; i<=sqrt(a); ) {
        if( prime[i] && (a % i == 0) ) {
            factors.push_back(i);
            a = a / i;
        } else {
            i++;  // increase only when the division fails otherwise stick to current number
        }
    }

    if(a!=1) {
        factors.push_back(a);
    }

    return factors;
}

vector<int> prime_factorization_without_prime_numbers(int a)
{
    vector<int> factors;

    // first remove all factors of 2
    while(a%2==0) {
        factors.push_back(2);
        a = a/2;
    }

    for(int i=3; i<=sqrt(a); i=i+2) {
        while(a%i==0) {
            factors.push_back(i);
            a = a/i;
        }
    }

    if(a!=1) {
        factors.push_back(a);
    }

    return factors;
}

vector<int> prime_factors(int a)
{
    vector<int> factors;
    if(ALGORITHM == 1) {
        factors = prime_factorization_with_prime_numbers(a);
    } else {
        factors = prime_factorization_without_prime_numbers(a);
    }
    return factors;
}

int main()
{
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    cout<<endl;

    vector<int> factors;
    factors = prime_factors(num);

    cout<<num<<" = ";
    for(int i=0; i < factors.size(); i++) {
        cout<<factors[i];
        if( (i+1) != factors.size()) {
            cout<<" * ";
        }
    }

    cout<<endl;
    return 0;
}


/*
                Theories
            ================

Algorithm: Prime Factorization

204 = 2*102; 102 = 2*51; 51 = 3*17
so, 204 = 2*2*3*17

The main idea is to Remove all the factors of the number one by one starting from 2.
The process can be terminated when the divisor is greater than square root of the number.
    Because, if both factors(say, a & b) were greater than the square root of the number(n),
    then a*b would be greater than n. So at least one of those factors must be less or equal to the square root of n.
    And, that is calculated/eliminated before from the number. (This is also for prime calculation).
Now, after all the factors are extracted, there will be a leftover.(Which is obviously a prime or 1).
If not 1, then it is the last factor.


i)
As, only prime numbers are factors,
Method-1 uses a prime number flag list to determine the factors.
Prime number flag list is generated by the Sieve of Eratosthenes algorithm
    Eratosthenes method:
    --------------------
        1. Create a list of consecutive integers from 2 to n: (2, 3, 4, .., n).
        2. Initially, let p equal 2, the first prime number.
        3. Starting from p, count up in increments of p and mark each of these numbers greater than p itself in the list.
           These numbers will be 2p, 3p, 4p, etc.; note that some of them may have already been marked.
        4. Find the first number greater than p in the list that is not marked.
           If there was no such number, stop. Otherwise, let p now equal this number (which is the next prime),
           and repeat from step 3.
    When the algorithm terminates, all the numbers in the list that are not marked are prime.
    This is said to be one of the fastest algorithm to find primes.
    Complexity: O( n(log n)log(log(n)) ) ( No fucking idea about this. )

ii)
Method-2 does not implement/need prime calculation.
Besides, it first removes all the factors of 2.
Then move on only with the odd numbers, which brings the no. of iteration to almost half.
Complexity: O( (sqrt(2))^n ); Worst case: O( sqrt(n) )
This method looks faster. Don't know for sure. :( But the first one looks cool.

*/
