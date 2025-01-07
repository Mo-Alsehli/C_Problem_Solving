/*
https://codeforces.com/group/MWSDmqGsZm/contest/223207/problem/B
*/


#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    // Cycle of last digits for 8^n: [8, 4, 2, 6]
    int last_digit[] = {6, 8, 4, 2};

    if (n == 0) {
        cout << 1 << endl; // 8^0 = 1
    } else {
        int index = n % 4;
        cout << last_digit[index] << endl;
    }

    return 0;
}
