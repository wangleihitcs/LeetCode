//
//  152MaximumProductSubarray.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/3/27.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、动态规划，时间复杂度O(n)，空间复杂度O(1)
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int res = nums[0];
        int imax = res;
        int imin = res;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0) {
                swap(imax, imin);
            }
            imax = max(nums[i], nums[i] * imax);
            imin = min(nums[i], nums[i] * imin);
            res = max(res, imax);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {-1, 2, 2, 3, -1, 0, 3, 10};
    Solution s;
    cout << s.maxProduct(nums) << endl;
}
