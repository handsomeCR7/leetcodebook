#include<iostream>
using namespace std;

class Solution {
public:
    int iceBreakingGame(int num, int target) {
        int dp = 0;
        for (int i = 2; i <= num; i++) {
            dp = (dp + target) % i;
        }
        return dp;
    }
};

int main() {
    int num = 7;
    int target = 4;
    Solution s;
    cout << s.iceBreakingGame(num, target) << endl;
    system("pause");
    return 0;
}