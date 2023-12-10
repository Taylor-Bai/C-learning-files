#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// 右旋字符串
class Solution{
public:
    void reverse(string& s, int a, int b){              // 重写左闭右闭的翻转  
        for(int start = a, end = b; a < b; a++, b--){
            swap(s[a],s[b]);
        }
    }

    string twiststr(string s, int a) {
        reverse(s,0,s.size() - 1);          // 全部翻转

        reverse(s,0,a - 1);                 // 局部翻转
        reverse(s,a,s.size() - 1);
        return s;
    }

};

int main(){
    Solution a;
    string b = "helloworld";
    string c ;
    c = a.twiststr(b,5);
    
    return 0;
}
