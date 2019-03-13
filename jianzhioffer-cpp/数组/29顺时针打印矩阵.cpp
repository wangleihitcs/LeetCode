//
//  29printMatrix.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/13.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int>> matrix) {
        vector<int> res;
        int rows = matrix.size();
        int cols = matrix[0].size();
        if(rows <= 0 || cols <= 0) return res;
        
        int start = 0;
        while(rows > start * 2 && cols > start * 2) {
            printMatrixCicle(matrix, res, rows, cols, start);
            start++;
        }
        
        return res;
    }
    
    void printMatrixCicle(vector<vector<int>>& matrix, vector<int>& res, int rows, int cols, int start) {
        int endRow = rows - start;
        int endCol = cols - start;
        
        //1.from left to right
        for(int j = start; j < endCol; j++)
            res.push_back(matrix[start][j]);
        
        //2.from top to down
        if(start < endRow - 1) {
            for(int i = start+1; i < endRow; i++)
                res.push_back(matrix[i][endCol-1]);
        }
        
        //3.from right to left
        if(start < endRow - 1 && start < endCol - 1) {
            for(int j = endCol-2; j >= start; j--)
                res.push_back(matrix[endRow-1][j]);
        }
        
        //4.from down to top
        if(start < endCol - 1 && start < endRow - 2) {
            for(int i = endRow-2; i > start; i--)
                res.push_back(matrix[i][start]);
        }
    }
};


int main() {
    vector<vector<int>> matrix = {
        {1,2,3},
        {5,6,7},
        {9,10,11},
        {15,16,17},
        {20,21,22}
    };
    
    Solution s;
    vector<int> res = s.printMatrix(matrix);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}
