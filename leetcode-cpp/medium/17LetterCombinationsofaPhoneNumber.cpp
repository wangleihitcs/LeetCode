//
//  17LetterCombinationsofaPhoneNumber.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/3/28.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、暴力枚举，时间复杂度O(3^M * 4^N)
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits == "") return res;
        
        static const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        //1. put a seed
        res.push_back("");
        
        //2. backtracking
        for(int i = 0; i < digits.size(); i++) {
            int num = digits[i] - '0';
            if(num > 9 || num < 0) break;
            vector<string> temp;
            for(int j = 0; j < v[num].size(); j++) {
                for(int k = 0; k < res.size(); k++) {
                    temp.push_back(res[k] + v[num][j]);
                }
            }
            res = temp;
        }
        
        return res;
    }
};

int main() {
    string digits = "23";
    Solution s;
    vector<string> res = s.letterCombinations(digits);
    for(auto str : res) {
        cout << str << " ";
    }
    cout << endl;
}
