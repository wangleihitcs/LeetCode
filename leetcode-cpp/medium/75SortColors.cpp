//
//  75SortColors.cpp
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
    //方法一、排序，时间复杂度O(nlogn)，空间复杂度O(1)，4ms，8.6MB
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
    
    //方法二、原地，时间复杂度O(n)，空间复杂度O(1)，12ms，8.6MB
    void sortColors2(vector<int>& nums) {
        int zero_index = leftSame(nums, 0, nums.size()-1, 0);
        int one_index = leftSame(nums, zero_index, nums.size()-1, 1);
    }
    int leftSame(vector<int>& nums, int left, int right, int target) {
        while(left < right) {
            while(right >= 0 && nums[right] != target)
                right--;
            while(left < nums.size() && nums[left] == target)
                left++;
            if(left < right)
                swap(nums[left], nums[right]);
        }
        return left;
    }
};

int main() {
    vector<int> nums = {0,0,0,0};
    Solution s;
    s.sortColors2(nums);
    for(int x : nums) {
        cout << x << " ";
    }
    cout << endl;
}
