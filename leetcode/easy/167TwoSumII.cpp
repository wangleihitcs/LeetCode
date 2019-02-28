//
//  167.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/2/22.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、暴力枚举，时间复杂度O(n^2)，552ms
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size()-1; i++) {
            for(int j = i+1; j < numbers.size(); j++) {
                if(numbers[i] + numbers[j] == target) return {i+1, j+1};
            }
        }
        return {0, 0};
    }
    
    //方法二、两个指针，时间复杂度O(n)，空间复杂度O(1)，8ms
    vector<int> twoSum1(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        int sum = 0;
        while(left < right) {
            sum = numbers[left] + numbers[right];
            if(sum == target) return {left+1, right+1};
            
            if(sum > target) right--;
            else left++;
        }
        return {0, 0};
    }
};

int main() {
    Solution so;
    vector<int> numbers = {2, 7, 11, 15};
    
}
