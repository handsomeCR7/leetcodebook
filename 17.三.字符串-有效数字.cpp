#include <iostream>
using namespace std;


//class Solution {
//public:
//    bool validNumber(string s) {
//        int i = 0;
//        int zhengfu = 0;
//        while (s[i] == ' ')
//        {
//            i++;
//        }
//        if (s[i] == '+' || s[i] == '-')
//        {
//            i++;
//        }
//        if (i >= s.size())
//        {
//            return false;
//        }
//        int dian = 1;
//        while (i < s.size())
//        {
//            if (s[i] == '+' || s[i] == '-')
//            {
//                zhengfu = 1;
//                i++;
//            }
//            if (zhengfu != 0)
//            {
//                return false;
//            }
//            else if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
//            {
//                i++;
//                continue;
//            }
//            // 点判断
//            else if (s[i] == '.')    
//            {
//                // 如果后面还有.则直接错误
//                if (dian != 1) {
//                    return false;
//                }
//                if ( i - 1 >= 0 && ((s[i-1] - '0' >= 0 && s[i-1] - '0' <= 9)||s[i-1]==' '||s[i-1]=='+'||s[i-1]=='-')) //前面有数字
//                {
//                    // .后面如果没有格子，则正确结束
//                    if (i + 1 == s.size()&&(s[i - 1] == ' ' || s[i-1]=='+'||s[i-1]=='-'))
//                    {
//                        return false;
//                    }
//                    else if (i + 1 == s.size())
//                    {
//                        return true;
//                    }
//                    // .后面如果有格子，则必须是数字
//                    if ( i + 1 < s.size() && s[i + 1] != ' ' && s[i+1]!='e'&&(s[i + 1] - '0' < 0 || s[i + 1] - '0' > 9))   // 判断后面是不是数字
//                    {
//                        return false;
//                    }
//                }
//                else if (i - 1 >= 0 && s[i - 1] != ' '&&(   (s[i-1] - '0' < 0 || s[i-1] - '0' > 9) && (s[i - 1]!='+'&& s[i - 1]!='-')))
//                {
//                    return false;
//                }
//                else if (i - 1 >= 0)
//                {
//
//                }
//                else if (i - 1 < 0||s[i - 1] == ' ')  // 如果前面没有格子
//                {
//                    // .后面如果没有格子，则错误结束
//                    if (i + 1 == s.size())
//                    {
//                        return false;
//                    }
//                    // .后面如果有格子，则必须是数字
//                    if (i + 1 < s.size() && ( s[i + 1] - '0' < 0 || s[i + 1] - '0' > 9))   // 判断后面是不是数字
//                    {
//                        return false;           // 如果不是，就错误返回
//                    }
//                }
//                // 如果后面有格子，是数字，则i++
//                i++;
//                dian = 0;
//                continue;
//                
//            }   
//            
//            // e和E判断
//            else if (s[i] == 'e' || s[i] == 'E')
//            {
//                zhengfu = 0;
//                if (i - 1 < 0)  // 如果前面没有格子
//                {
//                    return false;
//                }
//                if (s[i - 1] != '.' && (s[i-1] - '0' < 0 || s[i-1] - '0' > 9))
//                {
//                    return false;
//                }
//                if (i + 1 < s.size()&&(s[i+1]=='+'|| s[i + 1] == '-' ||(s[i + 1] - '0' >= 0 && s[i + 1] - '0' <= 9)        ) )
//                {
//                    i++;
//                }
//                while (i < s.size())
//                {
//                    if ((s[i] == '+' || s[i] == '-')  && zhengfu == 0 )
//                    {
//                        zhengfu = 1;
//                        i++;
//                    }
//                    if ((s[i] == '+' || s[i] == '-') && zhengfu == 1)
//                    {
//                        return false;
//                    }
//
//                    if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
//                    {
//                        i++;
//                    }
//                    else if (s[i] == ' ')
//                    {
//                        goto L1;
//                    }
//                    else
//                    {
//                        return false;
//                    }
//                }
//                return true;
//            }
//            else if (s[i] == ' ')
//            {
//                L1: while (i < s.size())
//                {
//                    if (s[i]==' ')
//                    {
//                        i++;
//                    }
//                    else
//                    {
//                        return false;
//                    }
//                }
//                return true;
//            }
//            else
//            {
//                return false;
//            }
//
//        }
//        return true;
//    }
//};

class Solution {
public:
    bool validNumber(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') i++;
        if (i == n) return false;
        s = s.substr(i);
        while (s.back() == ' ') s.pop_back();
        bool numFlag = false, dotFlag = false, eFlag = false, flag = false;
        for (i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i])) numFlag = true;
            else if (s[i] == '.' && !dotFlag && !eFlag) dotFlag = true;
            else if ((s[i] == 'e' || s[i] == 'E') && ((dotFlag && numFlag) || numFlag) && !eFlag)
            {
                eFlag = true;
                numFlag = false;
            }
            else if ((s[i] == '+' || s[i] == '-') && (i == 0 || s[i - 1] == 'e' || s[i - 1] == 'E'))
            {
            }
            else return false;
        }
        return numFlag;
    }
};

int main17() {
    string str;
    str = "1e+1e ";
    Solution solution;
    bool res = solution.validNumber(str);
    cout << res;
    
    system("pause");
    return 0;
}