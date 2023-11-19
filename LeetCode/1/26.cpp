#include <vector>
#include <iostream>
using namespace std;

// 26.删除有序数组中的重复项

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sp = 0;
        int fp = 0;
        for(fp = 0;fp < nums.size();fp++){
            if(fp + 1 < nums.size() && nums[fp] == nums[fp+1]){
            }else{
                nums[sp++] = nums[fp];
            }
        }
        return sp;
    }
};





int main()
{
    Solution a;
    vector<int> b = {5,7,7,8,8,8,9,9,10};
    int c ;
    c = a.removeDuplicates(b);
    return 0;
};