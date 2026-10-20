#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 0) return;

    // Move n-1 disks from 'from' to 'aux'
    towerOfHanoi(n - 1, from, aux, to);

    // Move the nth (largest remaining) disk from 'from' to 'to'
    cout << "Move disk " << n << " from " << from << " to " << to << endl;

    // Move the n-1 disks from 'aux' to 'to'
    towerOfHanoi(n - 1, aux, to, from);
}

int main() {
    int n = 3; // number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A = source, C = destination, B = auxiliary
    return 0;
}