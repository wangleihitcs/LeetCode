//
//  36ValidSudoku.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/2.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、按照规则来，时间复杂度O(9*n)，空间复杂度O(1)，32ms，20.4MB
    bool isValidSudoku(vector<vector<char>>& board) {
        bool res = true;
        
        //1.each row valid
        for(int i = 0; i < 9; i++) {
            vector<int> ht(256, 0);
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                if(ht[board[i][j]] == 0) {
                    ht[board[i][j]]++;
                } else {
                    return false;
                }
            }
        }
        //2.each column valid
        for(int j = 0; j < 9; j++) {
            vector<int> ht(256, 0);
            for(int i = 0; i < 9; i++) {
                if(board[i][j] == '.') continue;
                if(ht[board[i][j]] == 0) {
                    ht[board[i][j]]++;
                } else {
                    return false;
                }
            }
        }
        //3.3*3 cells valid
        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3) {
                vector<int> ht(256, 0);
                for(int m = 0; m < 3; m++) {
                    for(int n = 0; n < 3; n++) {
                        if(board[i+m][j+n] == '.') continue;
                        if(ht[board[i+m][j+n]] == 0) {
                            ht[board[i+m][j+n]]++;
                        } else {
                            return false;
                        }
                    }
                }
            }
        }
        
        return res;
    }
};

int main() {
    
}
