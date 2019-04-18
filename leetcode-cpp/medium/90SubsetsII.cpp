//
//  90SubsetsII.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/16.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、回溯法，时间复杂度O(2^n)，空间复杂度O(2^n)，12ms，9.4MB
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> item;
        backtrack(res, item, 0, nums);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& item, int begin, vector<int> nums) {
        res.push_back(item);
        for(int i = begin; i < nums.size(); i++) {
            if (i == begin || nums[i] != nums[i - 1]) {//当i==begin，则继续回溯；当i!=begin且nums[i]!=nums[i-1]，继续回溯
                item.push_back(nums[i]);
                backtrack(res, item, i+1, nums);
                item.pop_back();
            }
        }
    }
};

int main() {
    vector<int> nums = {1,2,2};
    Solution s;
    vector<vector<int>> res = s.subsetsWithDup(nums);
    for(vector<int> item : res) {
        for(int x : item) {
            cout << x << " ";
        }
        cout << endl;
    }
}
