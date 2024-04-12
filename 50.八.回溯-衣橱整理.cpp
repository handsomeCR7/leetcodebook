#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int digit(int x) {
        if (x == 100) {
            return 1;
        }
        else if (x >= 10) {
            return (x / 10) + (x % 10);
        }
        else {
            return x;
        }
    }

    void dfs(int m, int n, int cnt, vector<vector<bool>>&grid) {
        if (m >= grid.size() || n >= grid[0].size() || grid[m][n] == 1) {
            return;
        }
        else if (digit(m) + digit(n) <= cnt) {
            if (grid[m][n] == 0) {
                grid[m][n] = 1;
                res++;
                dfs(m, n + 1, cnt, grid);
                dfs(m + 1, n, cnt, grid);
            }
            else {
                dfs(m, n + 1, cnt, grid);
                dfs(m + 1, n, cnt, grid);
            }
        }
    }

    int wardrobeFinishing(int m, int n, int cnt) {
        vector<vector<bool>>grid(m, vector<bool>(n, 0));
        dfs(0, 0, cnt ,grid);
        return res;
    }
    int res = 0;
};

int main() {
    int m = 36;
    int n = 11;
    int cnt = 15;
    Solution s;
    cout << s.wardrobeFinishing(m, n, cnt) << endl;
    system("pause");
    return 0;
}
