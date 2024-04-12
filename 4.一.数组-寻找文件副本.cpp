#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int findRepeatDocument(vector<int>& documents) {
        int temp = 0;
        int res[2];
        for (int i = 0; i < documents.size(); i++)
        {
            while (documents[i] != i)
            {
                if (documents[documents[i]] == documents[i]) // 如果当前遍历的值将要对应索引的值处已经为当前遍历的值，则说明此值有重复
                {
                    return documents[i];
                }
                else
                {
                    temp = documents[documents[i]];
                    documents[documents[i]] = documents[i];
                    documents[i] = temp;
                }
            }
        }

        return -1;
    }
};


int main4() {
    vector<int>documents;
    int num;
    while (cin >> num)
    { 
        documents.push_back(num);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    Solution solution;
    int res = solution.findRepeatDocument(documents);
    cout << res << endl;


    system("pause");
    return 0;
}