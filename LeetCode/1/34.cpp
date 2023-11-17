#include <vector>
#include <iostream>
using namespace std;

// 34.在排序数组中查找元素的第一个和最后一个位置
// 因为排序数组，可以使用二分法。使用两次二分法分别去得到最小索引与最大索引
// 最小与最大的区别在于nums[middle]==target等号条件下,如何执行。考虑一个target位于数组中间的情况，如果缩小右阈值，则去找最小索引；如果缩小左阈值，则是去找最大索引。
// 还需要考虑 两种条件下的输出 跳出while时阈值表示为[right,left]
// 有多个相同的数，找满足条件的最大值索引
// ans-1    ans     ans+1
//         right     left

// 有多个相同的数，找满足条件的最小值索引
// ans-1    ans     ans+1
// right    left    

class Solution {
public:
    int binarySearch(vector<int> nums,int target,bool direction){
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int middle=left+(right-left)/2;
            if(nums[middle] < target || nums[middle]==target && direction){     
                left = middle + 1;
            }
            else{
                right = middle - 1;
            }
        }
        return left;
        // if (direction){
        //     return right;
        // }else{
        //     return left;
        // }

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int rightIdx = binarySearch(nums,target,true);
        int leftIdx = binarySearch(nums,target,false);
        if(leftIdx<=rightIdx){
            return vector<int>{leftIdx,rightIdx};
        }
        return vector<int> {-1,-1};
    }
};


int main()
{
    Solution a;
    vector<int> b = {5,7,7,8,8,8,9,9,10};
    vector<int> c ;
    c = a.searchRange(b,8);

    return 0;
};