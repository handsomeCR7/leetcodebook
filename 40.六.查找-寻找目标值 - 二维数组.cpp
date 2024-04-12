#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    bool findTargetIn2DPlants(vector<vector<int>>& plants, int target) {
        int length = plants.size();
        for (int t = 0; t < length; t++)
        {
            int i = 0;
            int j = plants[t].size() - 1;
            int m = 0;
            while (i <= j)
            {
                m = (i + j) / 2;
                if (plants[t][m] < target)
                {
                    i = m + 1;
                }
                else if (plants[t][m] > target)
                {
                    j = m - 1;
                }
                else
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main40() {
    vector<vector<int>>plants = { {-5} };

    int target = -5;
    Solution s;
    bool res = s.findTargetIn2DPlants(plants, target);
    cout << res << endl;

    system("pause");
    return 0;
}