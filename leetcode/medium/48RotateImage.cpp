//
//  48RotateImage.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/2/26.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、暴力，时间复杂度O(n^2)，空间复杂度O(n^2)，8ms，9.3MB
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> b = matrix;
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                b[j][n-1-i] = matrix[i][j];
            }
        }
        matrix = b;
    }
    
    //方法二、交换，时间复杂度O(n^2)，空间复杂度O(1)，4ms，9.3MB
    void rotate2(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = i+1; j < matrix[i].size(); j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    s.rotate(matrix);
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
