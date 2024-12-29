/* 
codeforces: https://codeforces.com/group/MWSDmqGsZm/contest/223207/problem/A
*/


#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n, m, q;
    cin >> n >> m >> q;
    cin.ignore();

    vector<vector<char>> arr(n, vector<char>(m, '.'));

    int r1, c1, r2, c2;
    char c;

    for(int i = 0; i < q; i++){
        cin >> r1 >> c1 >> r2 >> c2 >> c;

         // Normalize the ranges to ensure r1 <= r2 and c1 <= c2
        if (r1 > r2) swap(r1, r2);
        if (c1 > c2) swap(c1, c2);

        for(int j = r1-1; j <= r2-1; j++){
            for(int k = c1-1; k <= c2-1; k++){
                arr[j][k] = c;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }

    return 0;
}