#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> spiralArray(vector<vector<int>>& array) {
        if (array.size() == 0)
        {
            return {};
        }
        int zuo_you = 0;
        int shang_xia = array[0].size() - 1;
        int you_zuo = array.size() - 1;
        int xia_shang = 0;
        vector<int>res;
        int t = 0;
        int i, j = 0;
        while (1)
        {
            // 左到右
            for (i = xia_shang; i <= shang_xia ; i++) {
                res.push_back(array[zuo_you][i]);
            }
            zuo_you++;
            if (zuo_you > you_zuo)
            {
                break;
            }

            for (i = zuo_you; i <= you_zuo; i++) {
                res.push_back(array[i][shang_xia]);
            }
            shang_xia--;
            if (shang_xia < xia_shang)
            {
                break;
            }

            for (i = shang_xia; i >= xia_shang; i--) {
                res.push_back(array[you_zuo][i]);
            }
            you_zuo--;
            if (you_zuo < zuo_you)
            {
                break;
            }

            for (i = you_zuo; i >= zuo_you; i--) {
                res.push_back(array[i][xia_shang]);
            }
            xia_shang++;
            if (xia_shang > shang_xia)
            {
                break;
            }
        }
        return res;

    }
};

int main5()
{
    Solution solution;
    vector<vector<int>>array;
    int num;
    int i = 0;
    while (cin >> num)
    {
        array.resize(i+1);
        array[i].push_back(num);
        char c = cin.get();
        if (c == '\t')
        {
            i++;
        }
        else if(c == '\n')
        {  
            break;
        }
        
    }
    
    vector<int>res = solution.spiralArray(array);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    system("pause");
    return 0;
}