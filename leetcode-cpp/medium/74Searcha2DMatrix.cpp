//
//  74Searcha2DMatrix.cpp
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
    //方法一、暴力，时间复杂度O(m*n)，空间复杂度O(1)，12ms，9.7MB
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(target == matrix[i][j]) return true;
            }
        }
        return false;
    }
    
    //方法二、二分，时间复杂度O(m + logn)，空间复杂度O(1)，12ms，9.7MB
    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        if(matrix.size() == 1 && matrix[0].size() == 0) return false;
        int i = 0, j = matrix[0].size()-1;
        while(target > matrix[i][j]) {
            i++;
            if(i == matrix.size()) return false;
        }
        
        int left = 0, right = matrix[0].size()-1;
        while(left <= right) {
            int index = (left + right) / 2;
            if(target == matrix[i][index]) return true;
            else if(target > matrix[i][index]) {
                left = index + 1;
            } else {
                right = index - 1;
            }
        }
        return false;
    }
};

int main() {
//    vector<vector<int>> matrix = {
//        {1,   3,  5,  7},
//        {10, 11, 16, 20},
//        {23, 30, 34, 50}
//    };
    vector<vector<int>> matrix = {{1}};
    Solution s;
    cout << s.searchMatrix2(matrix, 13) << endl;
}
