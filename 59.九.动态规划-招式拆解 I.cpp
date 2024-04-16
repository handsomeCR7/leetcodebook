#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int dismantlingAction(string arr) {
        // 以第i个招为截止
        // 建一个哈希表，每次循环填入一个元素，用于下一循环时查找此招是否在表中
        // 储存这从左到右各个元素最后一次出现的索引，相同元素只有一个key
        unordered_map<char, int> hash;
        int value;//索引
        int dp = 0;
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            // 如果前面没有重复元素
            if (hash.find(arr[i]) == hash.end()) {
                dp++;
            }
            // 如果有重复元素，更新该元素hash表的value,+1
            else {
                value = hash.find(arr[i])->second;
                // 计算以这招结尾的连招数
                dp = min(dp + 1, i - value);
            }
            hash[arr[i]] = i;
            res = max(res, dp);
        }
        return res;
    }
};

int main() {
    string arr = "tmmzuxt";
    Solution s;
    cout << s.dismantlingAction(arr) << endl;
    system("pause");
    return 0;
}