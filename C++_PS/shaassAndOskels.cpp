/* 
https://codeforces.com/group/MWSDmqGsZm/contest/223207/problem/J
*/


#include <iostream>
#include <vector>

using namespace std;


int main(){
    int wires;
    cin >> wires;
    vector <int> birds(wires);
    int i;
    for(i = 0; i < wires; i++){
        cin >> birds[i];
    }

    int shoots;
    cin >> shoots;

    for(i = 0; i < shoots; i++){
        int x, y;
        cin >> x >> y;

        if(x > 1){
            birds[x - 2] += y - 1;  
        }

        if(x < wires){
            birds[x] += (birds[x - 1] - y); 
        }
        birds[x - 1] = 0;
    }

    for(i = 0; i < wires; i++){
        cout << birds[i] << endl;
    }

    return 0;
}