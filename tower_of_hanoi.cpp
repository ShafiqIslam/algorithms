#include <iostream>
using namespace std;

int moves(0);

void Hanoi(int n, string source, string target, string temp)
{
    moves++;
    if(n == 1){
        cout << "Move disc " << n << " from " << source << " to " << target << endl;
    } else{
        Hanoi(n-1, source, temp, target);
        cout << "Move disc " << n << " from " << source << " to " << target << endl;
        Hanoi(n-1, temp, target, source);
    }
}

int main()
{

    int no_of_discs = 3;
    Hanoi(no_of_discs, "Source", "Target", "Temp");
    cout << endl << "It took " << moves << " moves. " << endl;

    cout<<endl;
    return 0;

}


/*

                        Theories
                    ================

Problem: Tower Of Hanoi

The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:
1. Only one disk can be moved at a time.
2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
3. No disk may be placed on top of a smaller disk.

Recursive algorithm:
--------------------
To move n discs from Source peg to Target peg:
    1. move n - 1 discs from Source to Temp. This leaves disc n alone on Source peg.
    2. move disc n from Source to Target.
    3. move n - 1 discs from Temp to Target so they sit on disc n.

Complexity:
-----------
 The minimum number of moves required to solve a Tower of Hanoi puzzle is 2^n - 1, where n is the number of disks.
 So, complexity = O( 2^n )

 */
