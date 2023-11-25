#include <vector>
#include <iostream>
#include <string>
#include<map>
#include<unordered_map>
using namespace std;

// 76.最小覆盖子串
// 滑动窗口法

class Solution {
public:
    unordered_map <char, int> ori, cnt;                // 声明两张哈希表具有键值对<char, int>
                                                       // ori用于储存字符串t的<字符，字符数>,cnt用于记录当前窗口内字符串中相同的<字符，字符数>

    bool check() {
        for (const auto &p: ori) {
            if (cnt[p.first] < p.second) {             // 检查两张哈希表每个字符的数量是否相等
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (const auto &c: t) {                    // const auto & 读取任意类型数据，不改变
            ++ori[c];
        }

        int l = 0, r = -1;
        int len = INT_MAX, ansL = -1, ansR = -1;

        while (r < int(s.size())) {
            if (ori.find(s[++r]) != ori.end()) {    // 右窗口逐一判断字符是否是ori中的
                ++cnt[s[r]];
            }
            while (check() && l <= r) {
                if (r - l + 1 < len) {              // 找到更小的有效窗口、则更新子串
                    len = r - l + 1;
                    ansL = l;
                }
                if (ori.find(s[l]) != ori.end()) {  // 左窗口判断字符是否是ori中的，是则-1
                    --cnt[s[l]];            
                }
                ++l;                    // 左窗口移动
            }
        }

        return ansL == -1 ? string() : s.substr(ansL, len);     
    }
};

int main()
{
    Solution a;
    string b = "ADOBECODEBANC";
    string c = "ABC";
    string d;
    d = a.minWindow(b,c);
    return 0;
};