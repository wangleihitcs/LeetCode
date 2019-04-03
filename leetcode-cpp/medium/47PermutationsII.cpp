//
//  47PermutationsII.cpp
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
    //方法一、回溯法，时间复杂度O(n!)，空间复杂度O(n!)，24ms，10.3MB
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, res);
        return res;
    }
    void backtrack(vector<int> nums, int begin, vector<vector<int>>& res) {
        if(begin == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        for(int k = begin; k < nums.size(); k++) {
            if(k != begin && nums[k] == nums[begin]) continue;
            swap(nums[begin], nums[k]);
            backtrack(nums, begin + 1, res);
        }
    }
    
};

int main() {
    vector<int> nums = {1,1,2,2};
    Solution s;
    vector<vector<int>> res = s.permuteUnique(nums);
    for(vector<int> num : res) {
        for(int x : num) {
            cout << x << " ";
        }
        cout << endl;
    }
}
