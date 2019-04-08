//
//  63UniquePathsII.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/8.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、DP，时间复杂度O(mn)，空间复杂度O(mn)，4ms，9.3MB
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<long long>> A(m, vector<long long>(n, 1));
        //1.给第一行和第一列初始化
        int temp = m+1;
        for(int i = 1; i <= m; i++) {
            if(obstacleGrid[i-1][0] == 1) {
                temp = i;
                break;
            }
        }
        for(int i = temp; i <= m; i++) {
            A[i-1][0] = 0;
        }
        
        temp = n+1;
        for(int j = 1; j <= n; j++) {
            if(obstacleGrid[0][j-1] == 1) {
                temp = j;
                break;
            }
        }
        for(int j = temp; j <= n; j++) {
            A[0][j-1] = 0;
        }
        if(m == 1 || n == 1) return A[m-1][n-1];
        //2.利用迭代公式求解
        for(int i = 2; i <= m; i++) {
            for(int j = 2; j <= n; j++) {
                if(obstacleGrid[i-1][j-1] == 1) {
                    A[i-1][j-1] = 0;
                } else {
                    A[i-1][j-1] = A[i-2][j-1] + A[i-1][j-2];
                }
            }
        }
        
        return A[m-1][n-1];
    }
};

int main() {
    vector<vector<int>> obstacleGrid = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    Solution s;
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
}
