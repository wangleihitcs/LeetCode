//
//  80RemoveDuplicatesfromSortedArrayII.cpp
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
    //方法一、暴力解法，时间复杂度O(n^2)，空间复杂度O(1)，16ms，8.7MB
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        
        //1.get lenthg, O(n)
        int res = 0;
        for(int i = 0; i < nums.size()-2; i++) {
            if(nums[i] == nums[i+1] && nums[i] == nums[i+2]) continue;
            else
                res++;
        }
        res += 2;
        
        //2.get nums, O(n^2)
        int i = 0;
        while(i < nums.size()-2) {
            bool is_same = true;
            for(int k = i+1; k < nums.size(); k++) {
                if(nums[k] != nums[i]) {
                    is_same = false;
                    break;
                }
            }
            if(is_same) return res;
            if(nums[i] == nums[i+1] && nums[i] == nums[i+2]) {
                int temp = nums[i];
                for(int j = i; j < nums.size()-1; j++) {
                    nums[j] = nums[j+1];
                }
                nums.back() = temp;
            } else {
                i++;
                if(i == res-1) break;
            }
        }
            
        return res;
    }
    
    //方法二、时间复杂度O(n)，空间复杂度O(1)，24ms，8.9MB
    int removeDuplicates2(vector<int>& nums) {
        int i = 0;
        for (int num : nums)
            if (i < 2 || num > nums[i-2])
                nums[i++] = num;
        return i;
    }
};

int main() {
    vector<int> nums = {1,1,1,1,1,1,1};
    Solution s;
    cout << s.removeDuplicates(nums) << endl;
}
