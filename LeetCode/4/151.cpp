#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


// 151.翻转字符串里的单词

// 给定一个字符串，逐个翻转字符串中的每个单词。
// 额外要求：不要使用辅助空间，空间复杂度要求为O(1)。
// 示例 1：
// 输入: "the sky is blue"
// 输出: "blue is sky the"



// 这里最好重写reverse函数，自带的reverse函数反转的区间是左闭右开reverse(s.begin(),s.end());
// 考虑到前后和词间有很多空格，所以需要一个去空格的函数
// 
// 反转函数主要部分，需要快指针去判断一个单词是否结束（后面是空格/已经到末尾）
class Solution{
public:

    void reverse(string& s, int a, int b){              // 重写左闭右闭的翻转  
        for(int start = a, end = b; a < b; a++, b--){
            swap(s[a],s[b]);
        }
    }

    //去除所有空格并在相邻单词之间添加空格, 快慢指针。
    void removeExtraSpaces(string& s) {                 
        int slow = 0;   
        for (int i = 0; i < s.size(); ++i) {    
            if (s[i] != ' ') {                          // 第一次检测到非空格
                if (slow != 0) s[slow++] = ' ';         // 如果慢指针不是第一个单词的话，添加一个空格
                while (i < s.size() && s[i] != ' ') {   // 非空格后面都是非空格，所以循环把数字填到慢指针中去
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);                                 // 因为是在本数组上消除空格，后面需要调整大小
    }

    string reverseWords(string s) {
        removeExtraSpaces(s); 
        reverse(s, 0, s.size() - 1);
        int start = 0; 
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { // 去空格后的字符串，可以用空格来判断，而不是s[i] != ' ' && s[i] == ' '
                reverse(s, start, i - 1);       
                start = i + 1;                  
            }
        }
        return s;
    }
};


class Solution1{
public:
    void reverse(string& s, int a, int b){
        for(int start = a, end = b; a < b; a++, b--){
            swap(s[start], s[end]);
        }
    }

    void removespaces(string& s){
        int sp(0);
        for(int fp(0); fp < s.size(); fp++){
            if(s[fp] != ' '){
                if(sp != 0){s[sp] = ' '; sp++;}
                while(fp < s.size() && s[fp] != ' '){
                    s[sp] = s[fp];
                    sp++;fp++;
                }
            }
        }
        s.resize(sp); 
    }

    string reverseWords(string s) {
        removespaces(s); 
        reverse(s, 0, s.size() - 1);
        int start = 0; 
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { // 去空格后的字符串，可以用空格来判断，而不是s[i] != ' ' && s[i] == ' '
                reverse(s, start, i - 1);       
                start = i + 1;                  
            }
        }
        return s;
    }
};

int main(){
    Solution1 a;
    string b = "the sky is blue";
    string c ;
    c = a.reverseWords(b);
    cout << c;
    
    return 0;
}