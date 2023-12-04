#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// 15. 三数之和
// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。
// 请你返回所有和为 0 且不重复的三元组。


// 难点在于：  组内元素可以重复  但是  组间不重复


// 输出的是三元组不是索引，可以随便做排序
// 双指针法，复杂度o(n^2)——一个遍历n*双指针法搜索n
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i(0);
        int left(1);
        int right = nums.size()-1;
        sort(nums.begin(),nums.end());
        vector<vector<int>> results;
        for(;i < nums.size()-2;i++){
            if(nums[i] > 0){                    // 剪枝，排序后当第一个数大于零时，不可能构成三元组
                return results;
            }

            // 对i的去重：当i与上一个i-1相同时，可以跳过当前i
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            
            left = i + 1;                       // 每一个i都要重新设置left和right的值
            right = nums.size() - 1;

            while (left < right){
                if(nums[i] + nums[left] + nums[right] > 0){
                    right--;
                }else if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                }else{
                    results.insert(results.end(),{nums[i],nums[left],nums[right]});

                    // 对left和right的去重
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;

                    // 找到答案，双指针同时收缩
                    right--;
                    left++;
                }
            }
        }
        return results;
    }
};
// 对i的去重错误1：
//            while(i > 0 && nums[i] == nums[i-1]){
//              i += 1;
//            }
// 测试数据[0,0,0,0]

// 对i的去重错误2：
//            if(i > 0 && nums[i] == nums[i+1]){
//               continue;
//            }
// i=i的情况包含i=i+1的所有情况，反之不成立，测试数据[-1,-1,-2]





int main(){
    Solution a;
    vector<int> nums({-1,0,1,2,-1,-4});
    vector<vector<int>> c;
    c = a.threeSum(nums);

    return 0;

}