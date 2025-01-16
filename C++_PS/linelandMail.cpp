/* 
https://codeforces.com/group/MWSDmqGsZm/contest/223207/problem/I
*/
#include <iostream>
#include <vector>
#include <climits> // For INT_MAX, INT_MIN
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cities(n);
    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }

    for (int i = 0; i < n; i++) {
        int mini, maxi;

        // Minimum distance is with a neighbor
        if (i == 0) {
            mini = cities[i + 1] - cities[i];
        } else if (i == n - 1) {
            mini = cities[i] - cities[i - 1];
        } else {
            mini = min(cities[i] - cities[i - 1], cities[i + 1] - cities[i]);
        }

        // Maximum distance is with either the first or last city
        maxi = max(cities[i] - cities[0], cities[n - 1] - cities[i]);

        cout << mini << " " << maxi << endl;
    }

    return 0;
}
