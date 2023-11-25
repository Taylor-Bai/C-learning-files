#include <vector>
#include <iostream>
#include <string>
#include<map>
#include<unordered_map>
using namespace std;


// 904.水果成篮。 

// 你只有 两个 篮子，并且每个篮子只能装 单一类型 的水果。每个篮子能够装的水果总量没有限制。
// 你可以选择任意一棵树开始采摘，你必须从每棵 树(包括开始采摘的树)上恰好摘一个水果采的水果应当符合篮子中的水果类型。
// 每采摘一次，你将会向右移动到下一棵树，并继续采摘。
// 一旦你走到某棵树前，但水果不符合篮子的水果类型，那么就必须停止采摘。

// 滑动窗口法
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int sp = 0;
        int len = 0;
        unordered_map <int, int> cnt;

        for(int fp = 0;fp < fruits.size();fp++){
            cnt[fruits[fp]]++;
            while(cnt.size() > 2){
                auto it = cnt.find(fruits[sp]);
                it->second--;
                if(it->second == 0){
                    cnt.erase(it);
                }
                sp++;
            }
            if(fp - sp + 1 > len){
                len = fp - sp + 1;
            }
        }
        return len;
    }
};


int main()
{
    Solution a;
    vector<int> fruits = {0,1,2,2};
    int d;
    d = a.totalFruit(fruits);
    return 0;
};