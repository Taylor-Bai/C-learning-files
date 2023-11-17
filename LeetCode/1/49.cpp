#include <iostream>
using namespace std;


// 34.找x的平方根

// 法一：二分法
// 使用二分法去查找:满足if条件的最大整数且退出循环时
// ans-1    ans     ans+1
//         right     left
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        while(left<=right){
            int middle=left+(right-left)/2;
            if((long long)middle*middle<=x){        // 扩大int的范围 避免下x^2溢出
                left = middle+1;        
            }else{
                right = middle-1;
            }
        }
        return right;
    }
};

// 牛顿法
// 用一阶泰勒展开做逼近
class Solution{
public:
    int mySqrt(int a) {
        if(a==0){
            return 0;
        }
        long double x = a;
        while(true){
            x = x-(x-a/x)/2;
            if(x*x-a<1e-7){
                break;
            }
        }
        return x;
    }
};



int main()
{
    Solution1 a;
    int c = a.mySqrt(8);

    return 0;
};