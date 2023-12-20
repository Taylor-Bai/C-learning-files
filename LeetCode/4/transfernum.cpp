#include <vector>
#include <iostream>
#include <string>
using namespace std;


// 替换数字

// 给定一个字符串 s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，而将每个数字字符替换为number。
// 例如，对于输入字符串 "a1b2c3"，函数应该将其转换为 "anumberbnumbercnumber"
// 要求要在原数组上进行操作！

// 数组不是动态空间，大小固定
class Solution {
public:
    string transfernum(string s) {
        int cnt(0);
        int lp = s.size() - 1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] > '0' && s[i] < '9'){
                cnt++;
            }
        }
        s.resize(s.size() + cnt*5);
        int fp = s.size() - 1;
        for(;lp >= 0; lp--){
            if(s[lp] >= '0' && s[lp] <= '9'){
                s[fp] = 'r';
                s[fp - 1] = 'e';
                s[fp - 2] = 'b';
                s[fp - 3] = 'm';
                s[fp - 4] = 'u';
                s[fp - 5] = 'n';
                fp -= 6;
            }
            else{
                s[fp] = s[lp];
                fp--;
            } 
        }
        return s;
    }
};

int main(){
    Solution a;
    string b = "a1b";
    string c ;
    c = a.transfernum(b);
    cout << c;
    
    return 0;
}