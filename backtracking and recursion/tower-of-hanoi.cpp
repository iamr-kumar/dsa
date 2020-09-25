/*Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:
1) Only one disk can be moved at a time.
2) Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
3) No disk may be placed on top of a smaller disk.*/

#include<bits/stdc++.h>

using namespace std;

// This is a simple recursive approach to solve for three rods. TC -> O(2^n)

void solveTowerOfHanoi(int n, char from, char to, char aux) {
    if(n == 1) {
        cout << "Move disk 1 from " << from << "to " << to << "\n";
        return;
    }
    solveTowerOfHanoi(n - 1, from, aux, to);
    cout << "Move disk " << n << "from " << from << "to " << to << "\n";
    solveTowerOfHanoi(n - 1, aux, to, from);
} 

int main() {
    int n;
    cin >> n;
    solveTowerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}