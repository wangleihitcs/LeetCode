//
//  31NextPermutation.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/2.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、直接找下一个，时间复杂度O(n)，空间复杂度O(1)，8ms，8.7MB
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while(i >= 0 && nums[i] >= nums[i+1])
            i--;
        if(i >= 0) {
            int j = nums.size() - 1;
            while(j >= 0 && nums[j] <= nums[i])
                j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};

int main() {
    vector<int> nums = {1,5,8,4,7,6,5,3,1};
    Solution s;
    s.nextPermutation(nums);
    for(int x : nums) {
        cout << x << " ";
    }
    cout << endl;
}
