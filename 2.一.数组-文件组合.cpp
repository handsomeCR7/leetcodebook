#include <iostream>
using namespace std;
#include <vector>


class Solution {
public:
    vector<vector<int>> fileCombination(int target) {
        vector<vector<int>>res;
        for (int i = target / 2; i >= 2; i--)
        {
            int zhongweishu_zhengshu = target / i;
            double zhongweishu_fudianxing = double(target)/  i;
            double zhongweishu_xiaoshu = zhongweishu_fudianxing - zhongweishu_zhengshu;
            // 只有两种情况成立
            // 判断中位数奇偶
            if (zhongweishu_xiaoshu == 0 && (i % 2==1))
            {
                vector<int>res1;
                int k = zhongweishu_zhengshu - (i / 2);
                if (k <= 0) {
                    continue;
                }
                for (int j = 0; j < i; j++)
                {
                    res1.push_back(k);
                    k++;
                }
                res.push_back(res1);
            }
            else if (zhongweishu_xiaoshu == 0.5 && (i % 2 == 0))
            {
                vector<int>res1;
                int k = zhongweishu_zhengshu - (i / 2 - 1);
                if (k <= 0) {
                    continue;
                }
                for (int j = 0; j < i; j++)
                {
                    res1.push_back(k);
                    k++;
                }
                res.push_back(res1);
            }
        }
        return res;
    }
};

int main2() {
    Solution s;
    int target;
    cin >> target;
    vector<vector<int>> Res = s.fileCombination(target);
    for (int i = 0; i < Res.size(); i++)
    {
        for (int j = 0; j < Res[i].size(); j++)
        {
            cout << Res[i][j]<< " ";
        }
        cout << endl;
        
    }
  
  
    system("pause");
    return 0;

}


