#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int countTarget(vector<int>& scores, int target) {
        return right(scores, target) - right(scores, target - 1);
    }
private:
    int right(vector<int>& scores, int target) {
        int i = 0;
        int j = scores.size() - 1;
        int m = 0;
        while (i <= j)
        {
            m = (i + j) / 2;
            if (scores[m] <= target)
            {
                i = m + 1;
            }
            else
            {
                j = m - 1;
            }
        }
        return i;
    }
};

int main38() {
    vector<int>score = {2, 2, 3, 4, 4, 4, 5, 6, 6, 8};
    int target = 4;

    Solution s;
    int res = s.countTarget(score, target);

    /*for (int i : score)
    {
        cout << i << endl;
    }*/

    cout << res << endl;

    system("pause");
    return 0;
}