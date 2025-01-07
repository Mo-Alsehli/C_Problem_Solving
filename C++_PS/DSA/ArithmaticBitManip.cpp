#include <iostream>

using namespace std;


class ArithmaticBitManipulation {

public:
    int add(int a, int b) {
        while(b != 0){
            int carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }

    int subtract(int a, int b){
        return add(a, add(~b, 1));
    }

    int multiply(int a, int b){
        int result = 0;
        while(b != 0){
            if(b & 1){
                result = add(result, a);
            }
            a <<= 1;
            b >>= 1;
        }

        return result;
    }

    int divide(int dividend, int divisor){
        int quotient = 0;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        dividend = abs(dividend);
        divisor = abs(divisor);

        while(dividend >= divisor){
            int temp = divisor, multiple = 1;
            while(dividend >= (temp << 1)){
                temp <<= 1;
                multiple <<= 1;
            }
            dividend -= temp;
            quotient = add(quotient, multiple);
        }

        return sign < 0 ? add(~quotient, 1) : quotient;
    }
};


int main(){
    ArithmaticBitManipulation operation;

    int addition = operation.add(5, 2);
    cout << addition << endl;
    int subtraction = operation.subtract(5, 2);
    cout << subtraction << endl;
    int multiplication = operation.multiply(5, 2);
    cout << multiplication << endl;
    int devision = operation.divide(5, 2);
    cout << devision << endl;

    return 0;
}
 