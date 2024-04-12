#include <iostream>
using namespace std;
#include <unordered_map>

class Solution {
public:
    char dismantlingAction(string arr) {
        unordered_map<char, bool> hmap;
        for (char c : arr)
            // hmap.find(c) == hmap.end() 查找现在正在添加的字符c之前有没有出现过。
            // 如果出现过，那么hmap.find(c) == hmap.end()就为假，给value赋值false；
            // 否则，如果之前没有出现过，hmap.find(c) == hmap.end()则为真，给value赋值true
            hmap[c] = hmap.find(c) == hmap.end();
        for (char c : arr)
            // 再遍历一遍，直到第一个出现true，进行返回
            if (hmap[c]) return c;
        return ' ';
    }
};

