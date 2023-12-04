#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;


// 383.赎金信
// 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
// 如果可以，返回 true ；否则返回 false 。magazine 中的每个字符只能在 ransomNote 中使用一次。


// 用map做字母->数量的映射
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> strcnt;
        for(int i=0; i < ransomNote.size(); i++){
            strcnt[ransomNote[i]-'a']++;
        }
        for(int i=0; i < magazine.size(); i++){
            strcnt[magazine[i]-'a']--;
        }
        for(int i=0; i < 26; i++){
            if(strcnt[i] > 0){
                return false;
            }
        }
        return true;
    }
};



// 数组法   (数组复杂度小于哈希，适用于字符串这些有限键值对)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int strcnt[26] = {0};
        for(int i=0; i < ransomNote.size(); i++){
            strcnt[ransomNote[i]-'a']++;
        }
        for(int i=0; i < magazine.size(); i++){
            strcnt[magazine[i]-'a']--;
        }
        for(int i=0; i < 26; i++){
            if(strcnt[i] > 0){
                return false;
            }
        }
        return true;
    }
};