#include<iostream>
using namespace std;

class Solution {
public:
    int digitOneInNumber(int num) {
        long digit = 1;
        int high = num / 10;
        int cur = num % 10;
        int low = 0;
        int n = num;
        int res = 0;
        while (n) {
            low = num % digit;
            cur = (num / digit) % 10;
            high = num / (digit * 10);

            if (cur == 0) {
                res += high * digit;
            }
            else if (cur == 1) {
                res += high * digit + low + 1;
            }
            else {
                res += (high + 1) * digit;
            }

            digit *= 10;
            n /= 10;

        }
        return res;
    }
};

int main() {
    int num = 824883294;
    Solution s;
    cout << s.digitOneInNumber(num) << endl;
    system("pause");
    return 0;
}
