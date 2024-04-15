#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int bestTiming(vector<int>& prices) {
        int dp = 0;
        int res = 0;
        // 在第i天卖能赚的最多的钱
        for (int i = 1; i < prices.size(); i++) {
            dp = dp - prices[i - 1] + prices[i];
            // 如果第i-1天买，第i天卖赚的多
            if (prices[i] - prices[i - 1] > dp) {
                dp = max(dp, prices[i] - prices[i - 1]);
            }
            
            // 更新最大的res
            if (dp > res) {
                res = dp;
            }
        }
        return res;
    }
};

int main() {
    vector<int> prices = { 1, 2 ,4 };
    Solution s;
    cout << s.bestTiming(prices) << endl;
    system("pause");
    return 0;
}