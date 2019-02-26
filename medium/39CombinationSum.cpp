//
//  39CombinationSum.cpp
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
    //方法一、递归，时间复杂度O()，空间复杂度O()，16ms
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> item;
        backTracking(candidates, target, res, item, 0);
        return res;
    }
    void backTracking(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& item, int begin) {
        if(target < 0) return;
        if(target == 0) {
            res.push_back(item);
            return;
        }
        for(int i = begin; i < candidates.size(); i++) {
            item.push_back(candidates[i]);
            backTracking(candidates, target - candidates[i], res, item, i);
            item.pop_back();
        }
    }
};
