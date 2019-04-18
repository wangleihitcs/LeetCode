//
//  81SearchinRotatedSortedArrayII.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/11.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、暴力，时间复杂度O(n)，空间复杂度O(1)，8ms，8.8MB
    bool search(vector<int>& nums, int target) {
        for(int num : nums)
            if(num == target) return true;
        return false;
    }
    
    //方法二、双指针，时间复杂度O(logn)，空间复杂度O(1)，8ms，8.6MB
    bool search2(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(target == nums[mid]) return true;
            if((target > nums[left] && target > nums[mid] && target > nums[right]) || (target < nums[left] && target < nums[mid] && target < nums[right])) {
                for(int i = left; i <= right; i++) {
                    if(target == nums[i]) return true;
                }
                return false;
            }
            if(target > nums[mid]) {
                if(target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            } else {
                if(target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {0,0,1,1,2,0};
    Solution s;
    cout << s.search2(nums, 2) << endl;
}
