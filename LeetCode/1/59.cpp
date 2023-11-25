#include <vector>
#include <iostream>
using namespace std;

// 59.螺旋矩阵
// 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> res(n,vector<int> (n,0));
            int px = 0;int py = 0;
            int len = n - 1;
            int cnt = 1;
            int startx = 0;int starty = 0;
            int loop = (n % 2 == 0)? (n*n):(n*n-1);
            while(cnt <= loop){
                for(py = starty,px = startx;py < starty + len;py++){
                    res[px][py] = cnt++;
                }
                for(;px < startx + len;px++){
                    res[px][py] = cnt++;
                }
                for(;py > starty;py--){
                    res[px][py] = cnt++;
                }
                for(;px > startx;px--){
                    res[px][py] = cnt++;
                }
                len -= 2;
                startx += 1;
                starty += 1;
            }
            if(n % 2 == 1){
                res[n/2][n/2] = n*n;
            }
            return res;
        }
    };


int main()
{
    Solution a;
    int d = 3;
    vector<vector<int>> b (d,vector<int> (d,0));
    b = a.generateMatrix(d);
    return 0;
};