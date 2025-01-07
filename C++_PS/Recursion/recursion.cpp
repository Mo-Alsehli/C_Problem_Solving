#include <iostream>

using namespace std;

// 3n+1 series.

int fn3n_1(int n){
    if(n == 1){
        return 1;
    }

    if(n % 2 == 0){
        return 1 + fn3n_1(n/2);
    }

    return 1 + fn3n_1(3*n + 1);
}


int main(){

    cout << fn3n_1(22) << endl;
    return 0;
}