//
//  189RotateArray.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/2/23.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一1、暴力枚举，时间复杂度O(kn)，空间复杂度O(1)，764ms
    void rotate(vector<int>& nums, int k) {
        for(int i = 0; i < k; i++) {
            int temp = nums.back();
            for(int j = nums.size()-1; j >= 1; j--) {
                nums[j] = nums[j-1];
            }
            nums[0] = temp;
        }
    }
    //方法一2、暴力枚举，时间复杂度O(kn)，空间复杂度O(1)，272ms
    void rotate1(vector<int>& nums, int k) {
        for(int i = 0; i < k; i++) {
            nums.insert(nums.begin(), nums[nums.size()-1]);
            nums.pop_back();
        }
    }
    
    //方法二、借助一个数组，时间复杂度O(n)，空间复杂度O(n)，20ms
    void rotate2(vector<int>& nums, int k) {
        vector<int> temp = nums;
        k = k % nums.size();
        for(int i = 0; i < k; i++) {
            temp[i] = nums[nums.size() - k + i];
        }
        for(int i = k; i < nums.size(); i++) {
            temp[i] = nums[i - k];
        }
        nums = temp;
    }
    
    //方法三、逆转数组，时间复杂度O(n)，空间复杂度O(1)，16ms
    void rotate3(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }
    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }
    
};

int main() {
    
}
