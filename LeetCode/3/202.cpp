#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

// 202.快乐数
// 编写算法判断是否为快乐数：定义为循环计算各个位置上的平方和，，，计算平方和的各个位置的平方和，，，直到=1


// 有可能无限循环，在循环过程中记录sum，出现重复的值则进入死循环，判断为不是快乐数


class Solution {
public:
    int getsum(int n){                  // 取出每个位置的数
        int sum = 0;
        while(n != 0){
            sum+=(n % 10)*(n % 10);     // 最低位的平方和
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> sum;
        bool flag(true);
        while(flag){
            flag = sum.insert(n).second;
            n = getsum(n);
            if(n == 1){
                return true;
            }
        }
        return false;
    }
};


int main(){
    Solution a;
    int b = 24;
    bool c;

    c = a.isHappy(b);

    return c;
}
