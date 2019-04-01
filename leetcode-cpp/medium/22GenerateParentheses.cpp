//
//  22GenerateParentheses.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/1.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、暴力，时间复杂度O(n*2^(2n))，空间复杂度O(2^(2n))，152ms，86.4MB
    vector<string> generateParenthesis(int n) {
        if(n <= 0) return {""};
        vector<string> res;
        string item = "";
        for(int i = 0; i < 2*n; i++) {
            item += "c";
        }
        int pos = 0;
        generateAll(res, item, pos, 2*n);
        return res;
    }
    void generateAll(vector<string>& res, string item, int pos, int length) {
        if(pos == length) {
            if(valid(item)) {
                res.push_back(item);
            }
        } else {
            item[pos] = '(';
            generateAll(res, item, pos+1, length);
            item[pos] = ')';
            generateAll(res, item, pos+1, length);
        }
    }
    bool valid(string item) {
        int balance = 0;
        for(int i = 0; i < item.size(); i++) {
            if(item[i] == '(') balance++;
            else
                balance--;
            if(balance < 0) return false;
        }
        return (balance == 0);
    }
    
    //方法二、回溯法，时间复杂度O(4^n/sqrt(n))，空间复杂度O(4^n/sqrt(n))，8ms，173MB
    vector<string> generateParenthesis2(int n) {
        if(n <= 0) return {""};
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }
    void backtrack(vector<string>& res, string item, int open, int close, int max) {
        if(item.size() == max * 2) {
            res.push_back(item);
            return;
        }
        if(open < max) {
            backtrack(res, item+"(", open+1, close, max);
        }
        if(close < open) {
            backtrack(res, item+")", open, close+1, max);
        }
    }
    
    //方法三、方法二的改进
    vector<string> generateParenthesis3(int n) {
        vector<string> res;
        if(n == 0) {
            res.push_back("");
        } else {
            for(int c = 0; c < n; c++) {
                for(string left : generateParenthesis3(c)) {
                    for(string right : generateParenthesis3(n-c-1)) {
                        res.push_back("(" + left + ")" + right);
                    }
                }
            }
        }
        return res;
    }
    
};

int main() {
    Solution s;
    vector<string> res = s.generateParenthesis3(3);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    
    return 0;
}
