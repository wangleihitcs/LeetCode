//
//  217ContainsDuplicate.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/2/23.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    //方法一、暴力枚举，时间复杂度O(n^2)，空间复杂度O(1)，2684ms，11.2MB
    bool containDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return false;
        for(int i = 0; i < nums.size()-1; i++) {
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
    
    //方法二、排序，时间复杂度O(nlogn)，空间复杂度O(1)，32ms，11.3MB
    bool containDuplicate2(vector<int>& nums) {
        if(nums.size() == 0) return false;
        sort(nums.begin(), nums.end());     //快速排序
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] == nums[i+1]) return true;
        }
        return false;
    }
    
    //方法三、map/set，时间复杂度O(nlogn)，空间复杂度O(n)，60ms，18.1MB
    bool containDuplicate3(vector<int>& nums) {
        set<int> s;
        for(int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        if(s.size() == nums.size()) return false;
        return true;
    }
    
    //方法四、哈希表思想，时间复杂度O(n)，空间复杂度O(n)，24ms，11.8MB
    bool containDuplicate4(vector<int>& nums) {
        if(nums.size() == 0) return false;
        int* a = new int[nums.size()];
        for(int i = 0; i < nums.size(); i++) {
            a[i] = 32767;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(a[nums[i] % nums.size()] == nums[i]) return true;
            a[nums[i] % nums.size()] = nums[i];
        }
        return false;
    }
    
};

int main() {
    
}
