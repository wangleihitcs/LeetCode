//
//  153Sum.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/8/2.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    //方法一、暴力枚举，时间复杂度O(n^3)，空间复杂度O(n)，time limit
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> set_list;
        vector<vector<int>> result;
        if(nums.size() <= 2) return result;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++) {
            for(int j = i+1; j < nums.size()-1; j++) {
                for(int k = j+1; k < nums.size(); k++) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        set_list.insert(temp);
                    }
                }
            }
        }
        
        set<vector<int>>::iterator it;
        for(it = set_list.begin(); it != set_list.end(); it++) {
            result.push_back(*it);
        }
        
        return result;
    }
    
    //方法二、利用TwoSum，时间复杂度O(n^2)，空间复杂度O(n)，1732ms，442.7MB
    vector<vector<int>> threeSum2(vector<int>& nums) {
        set<vector<int>> se;
        vector<vector<int>> result;
        if(nums.size() <= 2) return result;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++) {
            vector<vector<int>> item = getTwoSum(nums, i+1, nums.size()-1, nums[i]);
            if(item.size() > 0) {
                for(int j = 0; j < item.size(); j++) {
                    se.insert(item[j]);
                }
            }
        }
        
        set<vector<int>>::iterator it;
        for(it = se.begin(); it != se.end(); it++) {
            result.push_back(*it);
        }
        
        return result;
    }
    vector<vector<int>> getTwoSum(vector<int>& nums, int left, int right, int v) {
        vector<vector<int>> item;
        int sum = 0;
        while(left < right) {
            sum = nums[left] + nums[right];
            if(v + sum == 0) item.push_back({v, nums[left], nums[right]});
            if(v + sum > 0) {
                right--;
            } else {
                left++;
            }
        }
        return item;
    }
    
    //方法三(二的改进)、利用TwoSum，时间复杂度O(n^2)，空间复杂度O(n)，96ms，16.6MB
    vector<vector<int>> threeSum3(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() <= 2) return result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++) {
            int a = nums[i];
            if(a > 0) break;
            if(i > 0 && nums[i-1] == nums[i]) continue;
            //Use TwoSum, O(n)
            int left = i+1, right = nums.size()-1;
            while(left < right) {
                int b = nums[left], c = nums[right];
                if(a + b + c == 0) {
                    result.push_back({a, b, c});
                    left++;
                    right--;
                    while(left < right && nums[left-1] == nums[left]) {
                        left++;
                    }
                    while(left < right && nums[right] == nums[right+1]) {
                        right--;
                    }
                } else if(a + b + c > 0) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return result;
    }
    
};

int main() {
    vector<int> v = {0, 0, 0, 0};
    Solution s;
    vector<vector<int>> result = s.threeSum3(v);
    for(vector<vector<int>>::iterator it = result.begin(); it != result.end(); it++) {
        vector<int> temp = *(it);
        for(vector<int>::iterator it2 = temp.begin(); it2 != temp.end(); it2++) {
            cout << *(it2) << " ";
        }
        cout << endl;
    }
}
