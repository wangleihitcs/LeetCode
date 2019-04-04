//
//  55JumpGame.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/4.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、贪心，时间复杂度O(n)，空间复杂度O(1)，20ms，9.8MB
    bool canJump(vector<int>& nums) {
        int lasPos = nums.size() - 1;
        for(int i = lasPos; i >= 0; i--) {
            if(i + nums[i] >= lasPos) {
                lasPos = i;
            }
        }
        return lasPos == 0;
    }
    
    //方法二、回溯法，时间复杂度O()，空间复杂度O(1)，time limited
    bool canJump2(vector<int>& nums) {
        if(nums.size() == 1) return true;
        bool res = false;
        backtrack(nums, 0, res);
        return res;
    }
    void backtrack(vector<int>& nums, int begin, bool& res) {
        if(begin >= nums.size() - 1) {
            res = true;
            return;
        }
        int max_jump = nums[begin];
        while(max_jump >= 1) {
            backtrack(nums, begin + max_jump, res);
            max_jump--;
        }
    }
};

int main() {
    vector<int> nums = {2,0,0};
    Solution s;
    cout << s.canJump2(nums) << endl;
}
