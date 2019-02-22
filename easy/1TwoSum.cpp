//
//  1AddTwoNum.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/12/18.
//  Copyright © 2018 wanglei. All rights reserved.
//

#include <map>
#include <vector>
class Solution {
public:
    //方法一、O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() == 0 || nums.size() == 1) return {};
        map<int, int> m;
        map<int,int>::iterator it;
        for(int i = 0; i < nums.size(); i++) {
            it = m.find(target - nums[i]);
            if(it != m.end()) {
                return {it ->second, i};
            }
            m[nums[i]] = i;
        }
    }
};

int main() {
    
}
