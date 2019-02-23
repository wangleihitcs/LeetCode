//
//  219ContainsDuplicateII.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/2/23.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    //方法一、暴力枚举，时间复杂度O(n^2)，空间复杂度O(1)，3980ms，10.08MB
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() == 0) return false;
        for(int i = 0; i < nums.size()-1; i++) {
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[i] == nums[j] && j - i <= k) return true;
            }
        }
        return false;
    }
    
    //方法二、Map，时间复杂度O(nlogn)，空间复杂度O(n)，56ms，15.5MB
    bool containsNearbyDuplicate2(vector<int>& nums, int k) {
        if(nums.size() == 0) return false;
        map<int, int> m;
        m.insert(pair<int, int>(nums[0], 0));
        for(int i = 1; i < nums.size(); i++) {
            if(m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) {
                return true;
            } else {
                m[nums[i]] = i;
            }
            m.insert(pair<int, int>(nums[i], i));
        }
        return false;
    }
};

int main() {
    map<int, int> m;
    m.insert(pair<int, int>(1, 0));
    m.insert(pair<int, int>(0, 1));
    m.insert(pair<int, int>(1, 2));
    
    map<int, int>::iterator it;
    for(it = m.begin(); it != m.end(); it++) {
        cout << it ->first << " " << it ->second << endl;
    }
}
