#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<bool> prime;

void SieveOfEratosthenes(int n)
{
    prime.assign(n+1, true);  // because assignment starts with index 0

    int p = 2;
    while(p <= n) {
        prime[p] = false;
        p = p + 2;
    }

    for (p=3; p*p<=n; p=p+2)
    {
        if (prime[p])
        {
            // Update all multiples of p

            //for (int i=p*2; i<=n; i += p)
            for (int i=p*p; i<=n; i += 2*p)
                prime[i] = false;
        }
    }
}

int main()
{
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    cout<<endl;

    SieveOfEratosthenes(num);

    for(int i=2; i <= num; i++) {
        cout<<i<<" - "<<prime[i]<<endl;
    } return 0;

    cout<<"Primes up to "<< num << endl;
    for(int i=2; i <= num; i++) {
        if( prime[i] ) {
            cout<<i<<" ";
        }
    }

    cout<<endl;
    return 0;
}


/*
                        Theories
                    ================


Algorithm: Sieve of Eratosthenes
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

Example:
--------
2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20
2  3     5     7     9     11    13    15    17    19       (eliminate 2's multiples)
2  3     5     7           11    13          17    19       (eliminate 3's multiples)

No,need to check further. Because 4 is not prime (so, 4's multiples are already removed by its factor 2).
And 5 * 5 > 20. There is no need to check if the divisor is greater than square root of the number.
Because,
Say, n = a * b
Now, if both a & b were greater than the square root of n,
then a*b would be greater than n. So at least one of those factors must be less or equal to the square root of n.
So, that is removed before by its smaller factor. And so, when checking primality of a number, there is no need to check
after its square root. If there is no factor smaller than or equals its square root, the number must have to be a
prime.

The implementation is not alike basic algorithm.
Here, at first the 2's multiples are removed. Which left only the odd numbers to move on.
Then, proceed with the next prime number, and remove its multiples. Here, the basic algorithm says to start
from 2p, 3p, 4p, .. and so on. But, there is no need to check the numbers smaller than p*p, because, the multiples
2p, 3p, 4p, ... (p-1)p are already removed when checking with the smaller divisors (2,3, ...). Now, only numbers
greater than or equal to p*p need to be removed.
And, also, there is no need to increment like 2p,3p,4p... Because, all even occurrences are already removed.
So, just odd occurrences are needed to remove.
So, the updating goes like -> p*p, (p+2)p, (p+4)p ... up-to n.

*/
