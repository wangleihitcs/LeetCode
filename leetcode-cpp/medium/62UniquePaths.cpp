//
//  62UniquePaths.cpp
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
    //方法一、动态规划，递归，时间复杂度O()，空间复杂度O(1)，time limited
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1) return 1;
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
    
    //方法二、动态规划，时间复杂度O(mn，空间复杂度O(mn)，4ms，8.8MB
    int uniquePaths2(int m, int n) {
        vector<vector<int>> A(m, vector<int>(n, 1));
        for(int i = 2; i <= m; i++) {
            for(int j = 2; j <= n; j++) {
                A[i-1][j-1] = A[i-2][j-1] + A[i-1][j-2];
            }
        }
        return A[m-1][n-1];
    }
    
};

int main() {
    Solution s;
    cout << s.uniquePaths2(7, 1) << endl;
}
