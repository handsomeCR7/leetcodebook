#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 1);
        int i = 0;
        int j = 0;
        int k = 0;
        for (int t = 1; t < n; t++) {
            dp[t] = (min( min(dp[i] * 2, dp[j] * 3), dp[k] * 5) );
            if (dp[t] == dp[i] * 2) {
                i++;
            }
            if (dp[t] == dp[j] * 3) {
                j++;
            }
            if (dp[t] == dp[k] * 5) {
                k++;
            }
        }
        return dp.back();
    }
};

int main() {
    int n = 10;
    Solution s;
    cout << s.nthUglyNumber(n) << endl;
    system("pause");
    return 0;
}