#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


// 459.找出重复的子字符串
// 给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。


// 字符匹配方法
// 如果多次重复构成，那么拼接两个字符串产生的中间部分必然含有原字符串
// 时间复杂度o（3n），空间复杂度o（1）
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t.erase(t.begin());t.erase(t.end() - 1);        // 掐头去尾，防止识别了拼接前的s
        if(t.find(s) != string::npos) return true;
        return false;
    }
};



// KMP方法
// 目标是通过next前缀表去找到重复串的最小周期
// 重复子串的next前缀表类似[-1,-1,-1,0,1,2,3,4,5,6];next[len-1]就是最长子串的前缀索引，+1表示数量，(len - (next[len - 1] + 1))计算持续子串的周期数
class Solution1 {
public:
    void getnext(int* next, string& s){
        int j = -1;
        next[0] = j;
        for(int i = 1; i < s.size(); i++){
            while(j >= 0 && s[i] != s[j + 1]){
                j = next[j];
            }
            if(s[i] == s[j + 1]){
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        int next[s.size()];
        getnext(next, s);
        int len(s.size());
        if(next[len-1] != -1 && len % (len - (next[len - 1] + 1)) == 0){return true;}       // 计算持续子串的周期数
        return false;
    }
};

int main(){
    Solution1 a;
    string b2 = "ababa";
    
    bool c = a.repeatedSubstringPattern(b2);

    return 0;
}