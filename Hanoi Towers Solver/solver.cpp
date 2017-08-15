#include <iostream>
using namespace std;

void hanoi(int diskNo, char a, char b, char c) {
    if(diskNo == 1) {
        cout<<"move disc from "<<a<<" to "<<b<<endl;  // final step
    } else {
        hanoi(diskNo - 1, a, c, b);  // decrement nr of disks and change tower order
        cout<<"move disc from "<<a<<" to "<<b<<endl;  // display next move
        hanoi(diskNo - 1, c, b, a);  // decrement nr of disks and change tower order
    }
}
int main() {
    int diskNo;

    cout << "How many disks?" << endl;
    cin >> diskNo;

    hanoi(diskNo, 'A','B','C');

    return 0;
}
