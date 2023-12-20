#include <iostream>
#include <vector>
using namespace std;

// 27.移除元素
// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。
// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

// 双指针法（快慢指针法）： 通过一个快指针和慢指针在一个for循环下完成两个for循环的工作。快指针负责读，筛选、慢指针负责写。
// 复杂度o(n),空间o(1);
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowidx = 0;
        int fastidx = 0;      // 快指针
        for(fastidx = 0;fastidx < nums.size();fastidx++){
            if(nums[fastidx] == val){
                
            }else{
                nums[slowidx] = nums[fastidx];
                slowidx++;
            }
        }
        return slowidx;
    }
};


// 双向指针。利用元素顺序可以改变的特点，反向搜索找不等于val的值覆盖正向搜索中等于val的值
// while 用于表示在循环过程中带目的的寻找，找到不满足条件的值跳出循环
class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {
        int lidx = 0;
        int ridx = nums.size() - 1;      // 反向指针
        while(lidx <= ridx){
            while (lidx <= ridx && nums[ridx] == val){      // 去找右边不等于val的值，跳出时nums[ridx]!=val
                 ridx--;
            }
            while(lidx <= ridx && nums[lidx] != val){       // 去找左边等于val的值，跳出时num[lidx]==val
                 lidx++;
            }
            if(lidx < ridx){
                 nums[lidx] = nums[ridx];
                 ridx--;
                 lidx++;
            }
        }
        return lidx;                
    }
};

int main()
{
    Solution1 a;
    vector<int> b = {3,2,2,3};
    int c = a.removeElement(b,2);
    return 0;
};