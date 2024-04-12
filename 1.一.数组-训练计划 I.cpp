#include <iostream>
using namespace std;
#include <vector>


class Solution {
public:
    vector<int> trainingPlan(vector<int>& actions)
    {
        int i = 0;
        int j = actions.size() - 1;
        while (i < j)
        {
            while (i < j && actions[i] % 2 == 1)
            {
                i++;
            }
            while (i < j && actions[j] % 2 == 0)
            {
                j--;
            }
            // i查找到偶数时停止++，j查找到奇数时停止--。开始进行交换
            // 假设i一开始就找到了偶数，i=0不变，而j这边全是偶数没有奇数，则一直执行--操作，当两个靠近时j=1就不再--了。
            // 这时候换不换其实无所谓，因为从i=0，j=1及其右边全是偶数了。
            // 两者交换时，如果i，j不相邻，则交换后继续检测。
            swap(actions[i], actions[j]);
        }
        return actions;
    }
};

int main1() {
    Solution s;
    vector<int>Actions;
    /*Actions.push_back(1);
    Actions.push_back(2);
    Actions.push_back(3);
    Actions.push_back(4);
    Actions.push_back(5);*/

    int num;
    while (cin >> num)
    {
        Actions.push_back(num);
        if (cin.get() == '\n')
            break;
    }

    s.trainingPlan(Actions);
    for (int i = 0; i < Actions.size(); i++)
    {
        cout << Actions[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
    
}


