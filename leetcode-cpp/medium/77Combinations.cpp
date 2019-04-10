//
//  77Combinations.cpp
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
    //方法一、回溯法，时间复杂度O(nk)，空间复杂度O(nk)，88ms，11.8MB
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> item;
        int begin = 1;
        backtrack(res, item, begin, n, k);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& item, int begin, int n, int k) {
        if(item.size() == k) {
            res.push_back(item);
            return;
        }
        for(int i = begin; i <= n; i++) {
            item.push_back(i);
            backtrack(res, item, i + 1, n, k);
            item.pop_back();
        }
    }
};
