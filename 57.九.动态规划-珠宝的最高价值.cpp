#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int jewelleryValue(vector<vector<int>>& frame) {
        vector<int> dp(frame[0].size(), 0);
        dp[0] = frame[0][0];
        for (int i = 1; i < frame[0].size(); i++) {
            dp[i] = dp[i - 1] + frame[0][i];
        }
        // 拿第[i][j]个时的最高价值
        for (int i = 1; i < frame.size(); i++) {
            dp[0] = dp[0] + frame[i][0];
            for (int j = 1; j < frame[0].size(); j++) {
                dp[j] = max(dp[j], dp[j - 1]) + frame[i][j];
            }
        }
        return dp[frame[0].size() - 1];
    }
};

int main() {
    vector<vector<int>> frame = { {1, 2},
                                  {5, 6},
                                  {1, 1} };
    Solution s;
    cout << s.jewelleryValue(frame) << endl;
    system("pause");
    return 0;
}