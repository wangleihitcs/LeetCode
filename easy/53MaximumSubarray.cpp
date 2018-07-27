//
//  38CountAndSay.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/7/26.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSum;
    int maxSubArray(vector<int>& nums) {
        maxSum = nums[0];
        maxSub(nums, nums.size()-1);
        return maxSum;
    }
    
    int maxSub(vector<int>& v, int n) {
        if(n == 0) return v[0];
        int prev = maxSub(v, n-1);
        int curr = max(v[n], prev + v[n]);
        maxSum = max(maxSum, curr);
        return curr;
    }
};

int main() {
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout << s.maxSubArray(v) << endl;
}
