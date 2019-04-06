//
//  59SpiralMatrixII.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/6.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、一圈一圈，时间复杂度O(n^2)，空间复杂度O(n^2)，4ms，8.7MB
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int start = 1, x = 0, y = 0;
        while(x * 2 < n && y * 2 < n) {
            //1. from left to right
            for(int j = y; j <= n - y - 1; j++) {
                res[x][j] = start++;
            }
            //2. from top to down
            for(int i = x + 1; i <= n - x - 1; i++) {
                res[i][n - y - 1] = start++;
            }
            
            //3. from right to left
            for(int j = n - y - 2; j >= y; j--) {
                res[n - x - 1][j] = start++;
            }
            
            //4. from down to top
            for(int i = n - x - 2; i >= x + 1; i--) {
                res[i][y] = start++;
            }
            x++;
            y++;
        }
        return res;
    }
    
};

int main() {
    Solution s;
    vector<vector<int>> res = s.generateMatrix(5);
    for(auto nums : res) {
        for(auto x : nums) {
            cout << x << " ";
        }
        cout << endl;
    }
    
}
