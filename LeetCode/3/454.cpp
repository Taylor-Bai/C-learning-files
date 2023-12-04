#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// 454.四数相加2
// 给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
// 所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -2^28 到 2^28 - 1 之间，最终结果不会超过 2^31 - 1 。


// 因为要计算次数，且不需要去重，所以用哈希表对统计求和、次数
// 四数之和可以分别表示为两数之和的叠加

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> sumab;
        int count(0);
        for(int i :nums1){
            for(int j : nums2){
                sumab[i+j]++;
            }
        }
        for(int i :nums3){
            for(int j : nums4){
                count += sumab[0-(i+j)];
            }
        }
        return count;
    }
};

