#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool articleMatch(string s, string p) {
        s = '0' + s;
        p = '0' + p;
        vector<vector<bool>> dp(s.size(), vector<bool>(p.size()));
        dp[0][0] = 1;
        for (int i = 2; i < p.size(); i += 2) {
            if (dp[0][i - 2] == 1 && p[i] == '*') {
                dp[0][i] = 1;
            }
        }
        for (int i = 1; i < s.size(); i++) {
            for (int j = 1; j < p.size(); j++) {
                if (p[j] == '.' && dp[i - 1][j - 1] == 1) {
                    dp[i][j] = 1;
                }
                if (p[j] == s[i] && dp[i - 1][j - 1]) {
                    dp[i][j] = 1;
                }
                if (p[j] == '*') {
                    // x* = ''
                    if (dp[i][j - 2] == 1) {
                        dp[i][j] = 1;
                    }
                    // x* = 'x'或'xx'或'xxx'等等
                    // *的每一行x都是递增的：如第一行是''，第二行是'x'，第三行是'xx'
                    // 上一轮添加的x如果没有匹配上，那后面再添x就没意义了
                    // 如果上一轮添加的x匹配上了，看本次如果再添加一次x，将s[i]和p[j-1]进行比较
                    if (dp[i - 1][j] == 1 && s[i] == p[j - 1]) {
                        dp[i][j] = 1;
                    }
                    // 特别地
                    // 如果*前面是.，那这个*也是万能的了
                    // 如果上一轮添加的x已经匹配上了，那本轮的*和s[i]直接匹配成功
                    if (p[j - 1] == '.' && dp[i - 1][j] == 1) {
                        dp[i][j] = 1;
                    }
                }
            }
        }
        return dp[s.size() - 1][p.size() - 1];
    }
};

int main() {
    string s = "aaa";
    string p = ".*";
    Solution res;
    cout << res.articleMatch(s, p) << endl;
    system("pause");
    return 0;
}