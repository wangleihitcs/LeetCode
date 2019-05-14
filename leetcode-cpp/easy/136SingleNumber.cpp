//
//  136SingleNumber.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/5/2.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>
using namespace std;

class Solution {
public:
    //方法一、哈希，时间复杂度O(n)，空间复杂度O(n)，32ms，11.5MB
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for(int num : nums) {
            if(s.count(num) != 0)
                s.erase(num);
            else
                s.insert(num);
        }
        return *s.begin();
    }
    
    //方法二、异或/位运算，时间复杂度O(n)，空间复杂度O(1)，16ms，9.7MB
    int singleNumber2(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++) {
            nums[0] ^= nums[i];
        }
        return nums[0];
    }
    
    //方法三、数学，时间复杂度O(n)，空间复杂度O(n)，32ms，11.7MB
    int singleNumber3(vector<int>& nums) {
        unordered_set<int> s;
        int sum = 0;
        for(int num : nums) {
            if(s.count(num) == 0) {
                s.insert(num);
            }
            sum += num;
        }
        return 2 * accumulate(s.begin(), s.end(), 0) - sum;
    }
};

int main() {
    vector<int> nums = {-1,-1,2};
    Solution s;
    cout << s.singleNumber3(nums) << endl;
    int m = 10 ^ 4;
    cout << m << endl;
}
