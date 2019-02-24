//
//  16-3SumClosest.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/2/24.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、暴力枚举，时间复杂度O(n^3)，空间复杂度O(1)，356ms，9.5MB
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() <= 2) return 0;
        int result = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size()-2; i++) {
            for(int j = i+1; j < nums.size()-1; j++) {
                for(int k = j+1; k < nums.size(); k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if(abs(sum - target) < abs(result - target)) {
                        result = sum;
                    }
                }
            }
        }
        return result;
    }
    
    //方法二、排序，利用TwoSum，时间复杂度O(n^2)，空间复杂度O(1)，12ms，9.4MB
    int threeSumClosest2(vector<int>& nums, int target) {
        if(nums.size() <= 2) return 0;
        int result = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++) {
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(sum - target) < abs(result - target)) {
                    result = sum;
                } else if(sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
    
};

int main() {
    
}
