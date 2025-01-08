/* 
https://codeforces.com/group/MWSDmqGsZm/contest/223207/problem/E
*/


#include <iostream>
#include <string>
using namespace std;

int main() {
    string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
    char direction;
    string input;
    cin >> direction >> input;

    for (char ch : input) {
        size_t pos = keyboard.find(ch);
        if (pos != string::npos) {
            if (direction == 'R') {
                cout << keyboard[pos - 1]; // Safe as keyboard.find ensures valid position
            } else {
                cout << keyboard[pos + 1]; // Safe within bounds of string
            }
        }
    }
    cout << endl;

    return 0;
}
