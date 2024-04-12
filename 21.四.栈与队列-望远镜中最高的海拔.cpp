#include <iostream>
using namespace std;
#include <vector>


class Solution {
public:
    vector<int> maxAltitude(vector<int>& heights, int limit) {
        if (heights.empty())
        {
            return {};
        }
        int size = heights.size();
        vector<int>res;
        res.resize(size - limit + 1);
        int j = 0;
        for (int i = 0; i <= size - limit; i++)
        {
            j = i;
            res[i] = heights[j];
            for (int j = i + 1; j < i + limit; j++)
            {
                if (heights[j] > res[i])
                {
                    res[i] = heights[j];
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int>in;
    int num = 0;
    while (cin >> num)
    {
        in.push_back(num);
        if (cin.get() == '\n')
        {
            break;
        }
    }

    Solution solution;
    vector<int>res = solution.maxAltitude(in, 3);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
    cout << endl;

    system("pause");
    return 0;
}