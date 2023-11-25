#include <vector>
#include <iostream>
using namespace std;

// 209.长度最小的子数组
// 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。


// 滑动窗口法，
// 两个指针 sp，fp 表示窗口两端
// 复杂度分析：o(2n)  看每个元素被操作的次数，每个元素加入窗口一次、退出窗口一次，操作两次
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sp = 0;
        int fp = 0;
        int ans = nums.size() + 1;
        int sum = 0;
        while (fp < nums.size()){
            sum = sum + nums[fp];
            while(sum >= target){
                if(ans > fp-sp){ans = fp - sp + 1;}
                sum = sum - nums[sp];
                sp++;
            }
            fp++;
        }
        if(ans == nums.size() + 1){
            ans = 0;
        }
        return ans;
    }
};


int main()
{
    Solution a;
    vector<int> b = {2,3,1,2,4,7};
    int c = 7;
    int d;
    d = a.minSubArrayLen(c,b);
    return 0;
};