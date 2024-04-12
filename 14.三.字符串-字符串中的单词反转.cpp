#include <iostream>
using namespace std;


class Solution {
public:
    string reverseMessage(string message) {
        string res;
        int i = 0;
        int j = message.size() - 1;
        int k = 0;
        if (message.empty())
        {
            return res;
        }
        while (message[i] == ' ' || message[j] == ' ')
        {
            if (message[i] == ' ')
            {
                i++;
            }
            if (message[j] == ' ')
            {
                j--;
            }
            if (j < i)
            {
                return res;
            }
        }
        i = j;
        while (i >= 0)
        {
            while (i >= 0 && message[i] != ' ')
            {
                i--;
            }
            k = 1;
            while (k <= j - i)
            {
                res += message[i + k];
                k++;
            }
            res += ' ';
            while (i >= 0 && message[i] == ' ')
            {
                i--;
            }
            j = i;
        }
        res.pop_back();
        return res;
    }
};

int main14() {
    string message= " 1";
    Solution solution;
    string res = solution.reverseMessage(message);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
    cout << endl;

    system("pause");
    return 0;
}