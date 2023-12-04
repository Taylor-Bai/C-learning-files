#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;


// 1.两数之和
// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

// 不能用set,nums=[3,3],target=6 ,如果可以重复出现就可以用
// 也不能使用双指针法，因为返回的是索引，不能排序

// map法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> nummap;                      // 插入的map就是vector的值以及他的索引i
        int i(0);
        for (int num : nums){
            // if(nummap[target-num] != 0){                 // 不能这样写，直接索引没有的键，会产生一个新的键值对，值为0；
            if(nummap.find(target-num) != nummap.end()){    // 索引就用find
                return vector<int> ({i,nummap[target-num]});
            }
            nummap.insert(pair<int, int>(num, i));
            i++;
        }
        return {};
    }
};

int main(){
    Solution a;
    vector<int> b = {3,3};
    int target = 6;
    vector<int> c;
    c = a.twoSum(b,target);
    

    return 0;
}