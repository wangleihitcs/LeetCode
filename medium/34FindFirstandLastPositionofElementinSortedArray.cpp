//
//  34FindFirstandLastPositionofElementinSortedArray.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/2/25.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、暴力查找，时间复杂度O(n)，空间复杂度O(1)，12ms，10.9MB
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = -1, right = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(target == nums[i]) {
                if(left == -1) {
                    left = i;
                    right = i;
                } else {
                    right = i;
                }
            }
        }
        return {left, right};
    }
    
    //方法二、二分查找，时间复杂度O(logn)，空间复杂度O(1)，12ms，10.9MB
    vector<int> searchRange2(vector<int>& nums, int target) {
        int left = -1, right = -1;
        int l = 0, r = nums.size()-1, index;
        while(l <= r) { //注意
            int mid = (l+r)/2;
            if(target < nums[mid]) {
                r = mid - 1;
            } else if(target > nums[mid]) {
                l = mid + 1;
            } else {
                index = mid;
                while(index >= l && nums[index] == target) index--;
                left = index+1;
                
                index = mid;
                while(index <= r && nums[index] == target) index++;
                right = index-1;
                
                return {left, right};
            }
        }
        return {left, right};
    }
};

int main() {
    
}
