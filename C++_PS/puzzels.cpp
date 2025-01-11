/* 
https://codeforces.com/group/MWSDmqGsZm/contest/223207/problem/F
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    cin.ignore();
    vector<int> puzzels(m);
    for(int i = 0; i < m; i++){
        cin >> puzzels[i];
    }

    sort(puzzels.begin(), puzzels.end());

    int lowest = puzzels[n-1] - puzzels[0];

    for(int i = 1; (i+n-1) < m; i++){
        int curr = puzzels[i + n-1] - puzzels[i];
        if(curr < lowest){
            lowest = curr;
        }
    }

    cout << lowest << endl;

    return 0;
}