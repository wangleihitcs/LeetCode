//
//  60PermutationSequence.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/7.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、利用下一个排列，时间复杂度O(kn)，空间复杂度O(n)，164ms，8MB
    //注意：1 <= n <= 9，1 <= k << n!
    string getPermutation(int n, int k) {
        vector<int> nums(n, 0);
        for(int i = 0; i < n; i++) {
            nums[i] = i+1;
        }
        while(k > 1) {
            nextPermutation(nums);
            k--;
        }
        string str = "";
        for(int i = 0; i < n; i++) {
            str += nums[i] + '0';
        }
        return str;
    }
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
    
    //方法二、精妙解法，时间复杂度O(n)，空间复杂度O(1)，4ms，8MB
    string getPermutation2(int n, int k) {
        string res;
        string nums = "123456789";
        int f[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};//store n! total num
        --k;
        for (int i = n; i >= 1; --i) {
            int j = k / f[i - 1];
            k %= f[i - 1];
            res.push_back(nums[j]);
            nums.erase(nums.begin() + j);
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.getPermutation2(3, 5) << endl;
}
