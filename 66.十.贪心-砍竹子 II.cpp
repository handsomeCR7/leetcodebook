#include<iostream>
using namespace std;

class Solution {
public:
    int cuttingBamboo(int bamboo_len) {
        if (bamboo_len <= 3) {
            return 1 * (bamboo_len - 1);
        }
        int a = bamboo_len / 3;
        int b = bamboo_len % 3;
        long res = 1;
        if (b == 1) {
            for (int i = 0; i < a - 1; i++) {
                res = (res * 3) % 1000000007;
            }
            return  (res * 4) % 1000000007;
        }
        else if (b == 2) {
            for (int i = 0; i < a; i++) {
                res = (res * 3) % 1000000007;
            }
            return  (res * 2) % 1000000007;
        }
        for (int i = 0; i < a; i++) {
            res = (res * 3) % 1000000007;
        }
        return res;
    }
};

int main() {
    int bamboo_len = 120;
    Solution s;
    cout << s.cuttingBamboo(bamboo_len) << endl;
    system("pause");
    return 0;
}