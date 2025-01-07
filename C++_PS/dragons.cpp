/* 
https://codeforces.com/group/MWSDmqGsZm/contest/223207/problem/C
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int s, n;
    cin >> s >> n;

    vector<pair<int, int>> dragons(n);
    for (int i = 0; i < n; ++i) {
        cin >> dragons[i].first >> dragons[i].second; // strength, bonus
    }

    // Sort dragons by strength (ascending order)
    sort(dragons.begin(), dragons.end());

    // Fight dragons in order
    for (const auto &dragon : dragons) {
        if (s > dragon.first) {
            s += dragon.second; // Increase Kirito's strength by bonus
        } else {
            cout << "NO" << endl; // Kirito loses
            return 0;
        }
    }

    cout << "YES" << endl; // Kirito defeats all dragons
    return 0;
}


