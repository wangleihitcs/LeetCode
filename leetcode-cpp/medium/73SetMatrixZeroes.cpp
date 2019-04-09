//
//  73SetMatrixZeroes.cpp
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
    //方法一、暴力解法，时间复杂度O(m*n*(m+n))，空间复杂度O(mn)，64ms，11.9MB
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> A = matrix;
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < A[0].size(); j++) {
                if(A[i][j] == 0) {
                    setZerosRowCol(matrix, i, j);
                }
            }
        }
    }
    void setZerosRowCol(vector<vector<int>>& matrix, int i, int j) {
        for(int m = 0; m < matrix.size(); m++)
            matrix[m][j] = 0;
        for(int n = 0; n < matrix[0].size(); n++)
            matrix[i][n] = 0;
    }
    
    //方法二、方法一的优化，时间复杂度O(m*n)，空间复杂度O(m+n)，52ms，11.4MB
    void setZeroes2(vector<vector<int>>& matrix) {
        vector<int> rows(matrix.size(), 0);
        vector<int> cols(matrix[0].size(), 0);
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(rows[i] == 1 || cols[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    
    //方法三、原地，时间复杂度O(m*n)，空间复杂度O(1)，48ms，11.5MB
    void setZeroes3(vector<vector<int>>& matrix) {
        bool isCol = false;
        for(int i = 0; i < matrix.size(); i++) {
            if(matrix[i][0] == 0) isCol = true;
            for(int j = 1; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[0].size(); j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        //如果第一个数为0，第一行全置0
        if(matrix[0][0] == 0) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }
        //如果第一列存在0，则第一列全置0
        if(isCol) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {0,1,2,0},
        {3,4,5,2},
        {0,3,1,5}
    };
    Solution s;
    s.setZeroes3(matrix);
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
