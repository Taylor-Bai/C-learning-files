#include <vector>
#include <iostream>
using namespace std;

// 242.有效的字母易位词


class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for(int i=0; i < s.size(); i++){
            record[s[i]-'a'] ++ ;
        }
        for(int i=0; i < t.size(); i++){
            record[t[i]-'a'] -- ;
        }
        for(int i=0; i < 26; i++){
            if(record[i] != 0){
                return false;
            }
        }
        return true;
    }
};



int main(){
    Solution a;
    string b1 = "cat";
    string b2 = "car";
    bool c;

    c = a.isAnagram(b1,b2);

    return c;
}