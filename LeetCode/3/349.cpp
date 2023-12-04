#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

// 349.两个数组的交集


// 集合法
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> results;
        unordered_set<int> set1(nums1.begin(),nums1.end());      // 把vector中的数放到set中
        for(int num : nums2){                                    // 遍历vector的一种写法 for(int num : vector)
            if(set1.find(num) != set1.end()){                    // find——在集合中找num的索引
                results.insert(num);                             // 插入一个元素 
            }
        }
        return vector<int>(results.begin(),results.end());       // 把set中的数放到vector中
    }
};

// 增添数组范围后：
// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 1000
// 数组法
class Solution1 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> results;
        int temp[1003] = {0};
        for(int num : nums1){
            temp[num] = 1;
        }
        for(int num :nums2){
            if(temp[num] == 1){
                results.insert(num);
            }
        }
        return vector<int> (results.begin(),results.end());
    }
};


int main(){
    Solution1 a;
    vector<int> b1 = {1,2,3};
    vector<int> b2 = {2,3,4};
    vector<int> c;

    c = a.intersection(b1,b2);

    return 0;
}