/* 
https://codeforces.com/group/MWSDmqGsZm/contest/223207/problem/D
*/


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, b, d;
    cin >> n >> b >> d;

    vector<int> oranges(n);
    for (int i = 0; i < n; i++) {
        cin >> oranges[i];
    }

    int waste = 0, emptyCount = 0;

    for (int i = 0; i < n; i++) {
        if (oranges[i] <= b) {
            waste += oranges[i];
            if (waste > d) {
                emptyCount++;
                waste = 0;
            }
        }
    }

    cout << emptyCount << endl;
    return 0;
}


