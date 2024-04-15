#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // 计算ciphertext的位数，并且分离各个数
    vector<int> weishu(int ciphertext) {
        vector<int> number;
        if (ciphertext < 10) {
            number.push_back(ciphertext);
            return number;
        }
        while (ciphertext / 10 != 0) {
            number.push_back(ciphertext % 10);
            ciphertext /= 10;
        }
        number.push_back(ciphertext);
        reverse(number.begin(), number.end());
        return number;
    }

    int crackNumber(int ciphertext) {
        vector<int> shu = weishu(ciphertext);
        // 截止到第i个数字，有多少种解法
        // 和i-1，i-2有关
        int a = 1;
        int b = 1;
        if (shu.size() >= 2) {
            if (shu[0] * 10 + shu[1] <= 25) {
                b = 2;
            }
        }
        if (shu.size() == 1) {
            return a;
        }
        if (shu.size() == 2) {
            return b;
        }
        int temp;
        for (int i = 2; i < shu.size(); i++) {
            if (shu[i - 1] != 0 && shu[i - 1] * 10 + shu[i] <= 25) {
                temp = b;
                b = a + b;
                a = temp;
            }
            else {
                a = b;
            }
        }
        return b;
    }
};

int main() {
    int ciphertext = 506;
        /*2

        2 1
        21

        2 1 2
        21 2
        2 12

        2 1 2  6
        21 2   6
        2 1 2   6
        2 1 26
        21 26*/
    Solution s;
    cout << s.crackNumber(ciphertext) << endl;
    system("pause");
    return 0;
}