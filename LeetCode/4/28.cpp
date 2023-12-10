#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// 28.找出字符串匹配的下标

// 基于KMP算法的字符串匹配问题
// 本质还是用存储空间换执行速度
class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = -1;     // 初始时相等的前缀长度
        next[0] = j;
        for(int i = 1; i < s.size(); i++){          // i 表示后缀，j表示前缀
            while(j >= 0 && s[i] != s[j + 1]){      // 前后缀不相同了
                j = next[j];                        // 一直回退
            }
            if(s[i] == s[j + 1]){                   // 新的前缀是否和后缀相等
                j++;          
            }
            next[i] = j;                            // j的前缀长度赋给next，表示前i个子串的索引是j（最长匹配前后缀）
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = -1; // // 因为next数组里记录的起始位置为-1
        for (int i = 0; i < haystack.size(); i++) {             // i 是文本串索引
            while(j >= 0 && haystack[i] != needle[j + 1]) {     // 不匹配，循环遍历到匹配的位置
                j = next[j];                                    
            }
            if (haystack[i] == needle[j + 1]) {                 // 匹配，j和i同时向后移动
                j++; 
            }
            if (j == (needle.size() - 1) ) {                    // 文本串包含模式串
                return (i - needle.size() + 1);                 // 返回文本串第一个匹配位置的索引
            }
        }
        return -1;
    }
};


int main(){
    Solution a;
    string b1 = "aabaabaaf";
    string b2 = "aabaaf";
    
    int c = a.strStr(b1,b2);

    return 0;
}
