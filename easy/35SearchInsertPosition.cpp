//
//  35SearchInsertPosition.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/7/22.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int count = nums.size();
        for(int i = 0; i < count; i++){
            if(target <= nums[i]) {
                return i;
            }
        }
        return count;
    }
    
    int others(vector<int>& nums, int target) {
        int i = 0;
        for(; i < nums.size() && target > nums[i]; i++);
        return i;
    }
};

int main() {
    vector<int> testVector = {1,3,5,6};
    
    Solution s;
//    cout << s.searchInsert(testVector, 7) << endl;
    cout << s.others(testVector, 7) << endl;
}
