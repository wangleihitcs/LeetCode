//
//  18-4Sum.cpp
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
    //方法一、暴力枚举，时间复杂度O(n^4)，空间复杂度O(n^4)，1272ms，10.8MB
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() <= 3) return result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-3; i++) {
            if(i > 0 && nums[i-1] == nums[i]) continue;
            for(int j = i+1; j < nums.size()-2; j++) {
                if(j > i+1 && nums[j-1] == nums[j]) continue;
                for(int k = j+1; k < nums.size()-1; k++) {
                    if(k > j+1 && nums[k-1] == nums[k]) continue;
                    for(int l = k+1; l < nums.size(); l++) {
                        if(l > k+1 && nums[l-1] == nums[l]) continue;
                        if(nums[i] + nums[j] + nums[k] + nums[l] == target) {
                            result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        }
                    }
                }
            }
        }
        return result;
    }
    
    //方法二、排序，利用TwoSum，时间复杂度O(n^3)，空间复杂度O(n^4)，48ms，10.8MB
    vector<vector<int>> fourSum4(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() <= 3) return result;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size()-1;
        for(int i = 0; i < nums.size()-3; i++) {
            if(i > 0 && nums[i-1] == nums[i]) continue;
            for(int j = nums.size()-1; j > i; j--) {
                if(j < nums.size()-1 && nums[j+1] == nums[j]) continue;
                int left = i+1, right = j-1;
                while(left < right) {
                    if(nums[i] + nums[left] + nums[right] + nums[j] == target) {
                        result.push_back({nums[i], nums[left], nums[right], nums[j]});
                        right--;
                        left++;
                        while(left < right && nums[left-1] == nums[left]) left++;
                        while(left < right && nums[right+1] == nums[right]) right--;
                    } else if(nums[i] + nums[left] + nums[right] + nums[j] > target){
                        right--;
                    } else {
                        left++;
                    }
                }
            }
        }
        return result;
    }
};
