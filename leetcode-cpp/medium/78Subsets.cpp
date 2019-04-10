//
//  78Subsets.cpp
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
    //方法一、回溯法，时间复杂度O(2^n)，空间复杂度O(2^n)，8ms，9MB
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> item;
        backtrack(res, item, 0, nums);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& item, int begin, vector<int> nums) {
        res.push_back(item);
        for(int i = begin; i < nums.size(); i++) {
            item.push_back(nums[i]);
            backtrack(res, item, i + 1, nums);
            item.pop_back();
        }
    }
    
    //方法二、迭代，时间复杂度O(2^n)，空间复杂度O(2^n)，8ms，8.8MB
    vector<vector<int>> subsets2(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for(int num : nums) {
            int n = res.size();
            for(int i = 0; i < n; i++) {
                res.push_back(res[i]);
                res.back().push_back(num);
            }
        }
        return res;
    }
    
    //方法三、Bit Manipulation，时间复杂度O(2^n)，空间复杂度O(2^n)，12ms，8.9MB
    vector<vector<int>> subsets3(vector<int>& nums) {
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> res(p);
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    res[i].push_back(nums[j]);
                }
            }
        }
        return res;
    }
};

int main() {
    cout << 1 << 4 << endl;
}
