#include <vector>
#include <iostream>
using namespace std;



class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sp = 0;
        int fp = 0;
        for(;fp < nums.size();fp++){
            if(nums[fp] != 0){
                nums[sp++] = nums[fp];
            }
        }
        for(;sp < nums.size();sp++){
            nums[sp] = 0;
        }
    }
};




int main()
{
    Solution a;
    vector<int> b = {1};
    int c ;
    a.moveZeroes(b);
    return 0;
}