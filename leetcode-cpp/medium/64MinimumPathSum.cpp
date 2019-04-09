//
//  64MinimumPathSum.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/9.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、dp，时间复杂度O(mn)，空间复杂度O(mn)，20ms，10.9MB
    //其实可以原地做，空间复杂度O(1)
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0 || n == 0) return 0;
        vector<vector<int>> A = grid;   //store the path sum minum of i,j
        int temp = A[0][0];
        for(int j = 2; j <= n; j++) {
            A[0][j-1] = A[0][j-1] + temp;
            temp = A[0][j-1];
        }
        temp = A[0][0];
        for(int i = 2; i <= m; i++) {
            A[i-1][0] = A[i-1][0] + temp;
            temp = A[i-1][0];
        }
        for(int i = 2; i <= m; i++) {
            for(int j = 2; j <= n; j++) {
                A[i-1][j-1] = min(A[i-2][j-1], A[i-1][j-2]) + grid[i-1][j-1];
            }
        }
        return A[m-1][n-1];
    }
};

int main() {
    
}
