#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution {
public:
    bool validateBookSequences(vector<int>& putIn, vector<int>& takeOut) {
        stack<int>temp;
        int j = 0;
        for (int i = 0; i < putIn.size(); i++)
        {
            temp.push(putIn[i]);
            while (!temp.empty() && temp.top() == takeOut[j])
            {
                temp.pop();
                j++;
            }
        }
        return temp.empty();
    }
};

int main20() {
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
    vector<int>out;
    while (cin >> num)
    {
        out.push_back(num);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    
    Solution solution;
    bool res = solution.validateBookSequences(in, out);
    cout << res << endl;

    system("pause");
    return 0;
}