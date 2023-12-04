#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// 15. 四数之和
// 两个细节：
// 提示里nums<=10^9;加和时可能用到long
// 剪枝时，不同于三数之和为定值，target为负时不成立，比如[-4,-2,-2,-1,-1],target=-10

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums,int target) {
        int i(0);
        int j(1);
        int left(2);
        int right = nums.size()-1;
        sort(nums.begin(),nums.end());
        vector<vector<int>> results;
        for(;i < nums.size();i++){
            // 剪枝，后面的&&条件保证target非负
            if(nums[i] > target && target >= 0){                    
                break; // 这里使用break，统一通过最后的return返回
            }
            // 对i的去重：当i与上一个i-1相同时，可以跳过当前i
            if(i > 0 && nums[i] == nums[i-1]){
                continue; 
            }

            for(j = i + 1;j < nums.size();j++){
                // 剪枝，后面的&&条件保证target非负
                if(nums[i] + nums[j] > target && target >= 0){                    
                    break; // 这里使用break，统一通过最后的return返回
                }
                // 对j的去重
                if(j > i + 1 && nums[j] == nums[j-1]){
                    continue; 
                }

                left = j + 1;                       
                right = nums.size() - 1;    

                while (left < right){
                    if((long)nums[i] + nums[j] + nums[left] + nums[right] > target){
                        right--;
                    }else if((long)nums[i] + nums[j] + nums[left] + nums[right] < target){
                        left++;
                    }else{
                        results.insert(results.end(),{nums[i],nums[j],nums[left],nums[right]});

                        // 对left和right的去重
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;

                        // 找到答案，双指针同时收缩
                        right--;
                        left++;
                    }
                }

            }
        }
        return results;
    }
};




int main(){
    Solution a;
    vector<int> nums({-2,-1,-1,1,1,2,2});
    int d = 0;
    vector<vector<int>> c;
    c = a.fourSum(nums,d);

    return 0;

}