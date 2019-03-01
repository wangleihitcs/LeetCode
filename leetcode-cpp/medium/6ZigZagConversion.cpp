//
//  6.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/7/31.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.size()) return s;
        int length = s.size();
        int row = numRows, col = 0;
        if(length % (2*numRows - 2) == 0) {
            col = (length/(2*numRows - 2)) * (numRows - 1);
        } else {
            col = (length/(2*numRows - 2)) * (numRows - 1) + 1;
        }
        char a[row+1][col+1];
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                a[i][j] = ' ';
        
        int index = 0;
        for(int j = 0; j < col; j++) {
            int temp = j % (row-1);
            if(temp == 0) {
                for(int i = 0; i < row; i++) {
                    a[i][j] = s[index];
                    index++;
                }
            } else {
                a[row-temp-1][j] = s[index];
                index++;
            }
        }
        
        index = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(a[i][j] != ' ') {
                    s[index] = a[i][j];
                    index++;
                }
            }
        }
        return s;
    }
    
    string others(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;
        
        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }
        
        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};

int main() {
    string s = "Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.";
    Solution so;
    cout << so.convert(s, 10) << endl;
}
