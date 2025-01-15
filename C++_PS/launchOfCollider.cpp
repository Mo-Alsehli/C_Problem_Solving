/* 
https://codeforces.com/group/MWSDmqGsZm/contest/223207/problem/H
*/

#include <iostream>
#include <vector>
#include <string>
#include <climits> // For INT_MAX
#include <algorithm> // For std::min

using namespace std;

int main() {
    int n;
    cin >> n;
    string movements;
    cin >> movements;

    vector<int> particles(n);
    for (int i = 0; i < n; i++) {
        cin >> particles[i];
    }

    // Initialize the minimum collision time
    int time = INT_MAX;

    // Check for collisions between adjacent particles
    for (int i = 0; i < n - 1; i++) {
        if (movements[i] == 'R' && movements[i + 1] == 'L') {
            int currTime = (particles[i + 1] - particles[i]) / 2;
            time = min(time, currTime);
        }
    }

    // Output the result
    if (time != INT_MAX) {
        cout << time;
    } else {
        cout << -1;
    }

    return 0;
}
