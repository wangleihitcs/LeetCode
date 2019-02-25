//
//  33SearchinRotatedSortedArray.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/2/25.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、暴力查找，时间复杂度O(n)，空间复杂度O(1)，8ms，9.9MB
    int search(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            if(target == nums[i]) return i;
        }
        return -1;
    }
    
    //方法二、分治二分查找，时间复杂度O(logn)，空间复杂度O(1)，8ms，9.9MB
    int search2(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int left = 0, right = nums.size()-1;
        while(left < right) {
            int mid = (left + right)/2;
            if(target == nums[mid]) return mid;
            
            if(nums[left] <= nums[mid]) {
                if(target < nums[mid] && target >= nums[left]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if(target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return nums[left] == target ? left : -1;
    }
};
