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
class Solution{
public:

    void reverse(string& s, int a, int b){              // 重写左闭右闭的翻转  
        for(int start = a, end = b; a < b; a++, b--){
            swap(s[a],s[b]);
        }
    }
    void removeExtraSpaces(string& s) {                 //去除所有空格并在相邻单词之间添加空格, 快慢指针。
        int slow = 0;   
        for (int i = 0; i < s.size(); ++i) {    
            if (s[i] != ' ') {                          // 遇到空格跳过。
                if (slow != 0) s[slow++] = ' ';         // 遇到的第一个非空格即是第一个单词开头，手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
                while (i < s.size() && s[i] != ' ') {   // 补上该单词，遇到空格说明单词结束。
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);                                 // slow的大小即为去除多余空格后的大小。
    }

    string reverseWords(string s) {
        removeExtraSpaces(s); 
        reverse(s, 0, s.size() - 1);
        int start = 0; 
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { // 到达空格或者串尾，说明一个单词结束。进行翻转。
                reverse(s, start, i - 1);       // 翻转，注意是左闭右闭 []的翻转。
                start = i + 1;                  // 更新下一个单词的开始下标start
            }
        }
        return s;
    }
};

int main(){
    Solution a;
    string b = "  hello world  ";
    string c ;
    c = a.reverseWords(b);
    cout << c;
    
    return 0;
}