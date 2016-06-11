#include <iostream>
using namespace std;

void comb(int n, int r, int *arr, int sz)
{
    for (int i = n; i >= r; i--) {
        // choose the first element
        arr[r - 1] = i;
        if (r > 1) {
            comb(i - 1, r - 1, arr, sz);
        } else {
            for (int i = 0; i < sz; i ++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    const int N = 5;
    const int R = 3;
    int *arr = new int[R];
    comb(N, R, arr, R);
    return 0;
}
