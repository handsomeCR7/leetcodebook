#include <iostream>
using namespace std;


class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            return 1 / myPow1(x, -(long)(n));
        }
        
        return myPow1(x, n);
    }
private:
    double myPow1(double x, long n) {
        if (n == 0)
        {
            return 1;
        }
        double temp = myPow(x, n / 2);
        if (n % 2 == 0) {
            return temp * temp;
        }
        else {
            return temp * temp * x;
        }
    }
};


int main44() {
    Solution s;
    double res = s.myPow(1.0000000, -2147483648);
        
    cout << res << endl;

    system("pause"); 
    return 0;
}