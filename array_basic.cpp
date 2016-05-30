#include <iostream>
#include <math.h>
using namespace std;

int SIZE = 10;

int maximum(int *a)
{
    int max = a[0];
    for(int i=1; i<SIZE; i++) {
        if( max < a[i] ){
            max = a[i];
        }
    }
    return max;
}

int minimum(int *a)
{
    int min = a[0];
    for(int i=1; i<SIZE; i++) {
        if( min > a[i] ){
            min = a[i];
        }
    }
    return min;
}

int total(int *a)
{
    int total = a[0];
    for(int i=1; i<SIZE; i++) {
        total += a[i];
    }
    return total;
}

double mean(int *a)
{
    return total(a) / SIZE;
}


double variance(int *a)
{
    double m = mean(a);
    double sum = 0;
    for(int i=0; i<SIZE; i++) {
        sum += ( a[i] - m ) * ( a[i] - m );
    }

    return sum/SIZE;
}

double standard_deviation(int *a)
{
    return sqrt(variance(a));
}

int main()
{
    int a[10] = {10, 20, 12, 14, 9, 13, 17, 23, 14, 11};

    cout << "Maximum : " << maximum(a)<<endl;
    cout << "Minimum : " << minimum(a)<<endl;
    cout << "Total   : " << total(a)<<endl;
    cout << "Mean    : " << mean(a)<<endl;
    cout << "Variance: " << variance(a)<<endl;
    cout << "S.D.    : " << standard_deviation(a)<<endl;

    cout<<endl;
    return 0;
}


/*

                Theories
            ================

Data Structure: Basic Array with some Statistics

** Variance = sum( ( x[i] - mean ) ^ 2 ) / N = (SD)^2


*/

