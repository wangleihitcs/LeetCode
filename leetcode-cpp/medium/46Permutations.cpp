//
//  46Permutations.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/3.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、回溯法，时间复杂度O(n!)，空间复杂度O(n!)，12ms，9MB
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }
    void backtrack(vector<int>& nums, int begin, vector<vector<int>>& res) {
        if(begin == nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int i = begin; i < nums.size(); i++) {
            swap(nums[begin], nums[i]);
            backtrack(nums, begin + 1, res);
            swap(nums[begin], nums[i]); // reset
        }
    }
};

int main() {
    vector<int> nums = {1,2,3};
    Solution s;
    vector<vector<int>> res = s.permute(nums);
    for(vector<int> num : res) {
        for(int x : num) {
            cout << x << " ";
        }
        cout << endl;
    }
}
