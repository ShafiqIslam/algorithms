#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define N 3
int magicSquare[N][N];

void generateSquare(int n)
{
    memset(magicSquare, 0, sizeof(magicSquare));

    int i = n/2;
    int j = n-1;

    for (int num=1; num <= n*n; ) {
        if (i == -1 && j == n) {
            j = n-2;
            i = 0;
        } else {
            if (j == n) j = 0;

            if (i < 0) i = n-1;
        }

        if (magicSquare[i][j]) {
            j -= 2;
            i++;
            continue;
        } else {
            magicSquare[i][j] = num++;
        }

        j++; i--;
    }
}

void print()
{
    cout << "Magic square for : " << N << endl;;
    cout << "---------------------" << endl << endl;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            printf("%3d ", magicSquare[i][j]);
        printf("\n");
    }
}

int main()
{
    generateSquare(N);
    print();
    cout<<endl;
    return 0;
}

/*
            Theories
        ===============

1. 1 is stored at position (n/2, n-1).
2. 1. The position of next number is calculated by decrementing row number of previous number by 1,
   and incrementing the column number of previous number by 1. At any time, if the calculated row position becomes -1,
   it will wrap around to n-1. Similarly, if the calculated column position becomes n, it will wrap around to 0.
3. If the magic square already contains a number at the calculated position, calculated column position will be decremented by 2,
   and calculated row position will be incremented by 1.
4. WTF!!

*/
