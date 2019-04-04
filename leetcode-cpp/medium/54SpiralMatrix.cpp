//
//  54SpiralMatrix.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/4.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、一圈一圈遍历，时间复杂度O(m*n)，空间复杂度O(m*n)，4ms，8.6MB
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row = 0, col = 0;
        while(row * 2 < matrix.size() && col * 2 < matrix[0].size()) {
            cycleDisplay(res, matrix, row, col);
            row++;
            col++;
        }
        return res;
    }
    void cycleDisplay(vector<int>& res, vector<vector<int>> matrix, int row, int col) {
        int left_rows = matrix.size() - row * 2;
        int left_cols = matrix[0].size() - col * 2;
        
        //1.from left to right
        if(left_rows > 0 && left_cols > 0) {
            for(int j = col; j < col + left_cols; j++) {
                res.push_back(matrix[row][j]);
            }
        }
        left_rows--;
        //2.from top to down
        if(left_rows > 0 && left_cols > 0) {
            for(int i = row + 1; i < row + 1 + left_rows; i++) {
                res.push_back(matrix[i][col + left_cols - 1]);
            }
        }
        left_cols--;
        //3.from right to left
        if(left_rows > 0 && left_cols > 0) {
            for(int j = col + left_cols - 1; j >= col; j--) {
                res.push_back(matrix[row + left_rows][j]);
            }
        }
        left_rows--;
        //4.from down to up
        if(left_rows > 0 && left_cols > 0) {
            for(int i = row + left_rows; i >= row + 1; i--) {
                res.push_back(matrix[i][col]);
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,2,3},
        {6,7,8},
        {11,12,13},
        {9,4,5}
    };
    Solution s;
    vector<int> res = s.spiralOrder(matrix);
    for(int x : res) {
        cout << x << " ";
    }
    cout << endl;
}
