//
//  79WordSearch.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/10.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、回溯法，时间复杂度O(m*n*k)，空间复杂度O(1)，264ms，124.6MB
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(backtrack(board, word, i, j, 0, m, n, word.size())) return true;
            }
        }
        return false;
    }
    bool backtrack(vector<vector<char>>& board, string word, int i, int j, int start, int m, int n, int sLen){
        char curC = board[i][j];
        bool res = false;
        if(curC != word[start]) return false;
        if(start == sLen - 1) return true;
        board[i][j] = '*';
        if(i > 0) res = backtrack(board, word, i-1, j, start+1, m, n, sLen);
        if(!res && i < m - 1) res = backtrack(board, word, i+1, j, start+1, m, n, sLen);
        if(!res && j > 0) res = backtrack(board, word, i, j-1, start+1, m, n, sLen);
        if(!res && j < n - 1) res = backtrack(board, word, i, j+1, start+1, m, n, sLen);
        board[i][j] = curC;
        return res;
    }
};

int main() {
    string str = "";
    str.push_back('A');
    str.push_back('B');
    cout << str << endl;
    str.pop_back();
    cout << str << endl;
}
