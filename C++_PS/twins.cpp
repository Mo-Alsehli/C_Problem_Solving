/* 
https://codeforces.com/group/MWSDmqGsZm/contest/223207/problem/G
*/


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
    int n;
    cin >> n;

    vector<int> coins(n);

    int twinSum = 0;
    int i;
    for(i = 0; i < n; i++){
        cin >> coins[i];
        twinSum += coins[i];
    }

    int currSum = 0;
    i = 0;
    sort(coins.begin(), coins.end(), greater<int>());
    while(currSum <= twinSum && i < n){
        currSum += coins[i];
        twinSum -= coins[i];
        i++;
    }

    cout << i << endl;

    return 0;
}