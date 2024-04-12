#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool test(vector<vector<char>>& grid, int m ,int n, string target, int k) {
        if (m < 0 || n < 0 || m >= grid.size() || n >= grid[0].size() || grid[m][n] != target[k]) {
            return false;
        }
        else {
            grid[m][n] = '7'; 
            k++;
            if (k == target.size()) {
                return true;
            }
            else {
                bool res = test(grid, m - 1, n, target, k) || test(grid, m + 1, n, target, k) || test(grid, m, n - 1, target, k) || test(grid, m, n + 1, target, k);
                if (res == 0) {
                    k--;
                    grid[m][n] = target[k];
                    return false;
                }
                else {
                    return true;
                }
            }
            return false;
        }
    }

    bool wordPuzzle(vector<vector<char>>& grid, string target) {
        int k = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (test(grid, i, j, target, k)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>>grid = { {'C', 'A', 'A'},{'A', 'A', 'A'},{'B', 'C', 'D'} };
    string target = "AAB";
    Solution s;
    cout << s.wordPuzzle(grid, target) << endl;
    system("pause");
    return 0;
}