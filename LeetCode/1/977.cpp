#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int p = 0;int q = nums.size() - 1;int inv = nums.size() - 1;
        for (;p <= q;inv--){
            if(nums[p]*nums[p] < nums[q]*nums[q]){
                ans[inv] = nums[q]*nums[q];
                q--;
            }else{
                ans[inv] = nums[p]*nums[p];
                p++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution a;
    vector<int> b = {-4,-1,0,3,10};
    vector<int> c ;
    c = a.sortedSquares(b);
    return 0;
};