#include <vector>
#include <iostream>
using namespace std;

// 搜索插入位置，输出索引是大于输入target的位置的最小整数

// 二分法搜索，左闭右闭，
// 当target属于[min(vector), max(vector)]时，搜索过程中左右域不断内缩，直至right=left=middle。
// 此时target如果还是大于right/left，left+1越界，输出right+1；如果小于right/left，right-1越界，输出right+1。

// 当target位于两侧数组外时，一侧阈值快速收敛到另一侧(eg.[0,0]/[5,5])。然后越界([0,-1]/[6,5])，输出0/6S；

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left <= right)
        {
            int middle = left + (right - left)/2;       // 避免越界
            if(nums[middle] < target){
                left = middle + 1;                      // +1  -1用于产生越界
            }
            else if(nums[middle] > target){
                right = middle - 1;
            }
            else{
                return middle;
            }
        }
        return right + 1 ;
    }
 };


// 优化版本
class Solution1 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]<target)
                l=mid+1;
            else r=mid-1;
        }
        return l;
    }
};


int main()
{
    Solution a;
    vector<int> b = {1,3,5,7,9};
    int c ;
    c = a.searchInsert(b,10);

    cout<<c;
    return 0;
};


