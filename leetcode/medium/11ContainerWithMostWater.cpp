//
//  11ContainerWithMostWater.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/8/1.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // O(n^2)
    int maxArea(vector<int>& height) {
        int max = 0;
        for(int i = 0; i < height.size()-1; i++) {
            for(int j = i+1; j < height.size(); j++) {
                int temp = min(height[i], height[j]) * (j-i);
                if(temp > max) {
                    max = temp;
                }
            }
        }
        return max;
    }
    
    //O(n)
    int others(vector<int>& height) {
        int max = 0, left = 0, right = height.size()-1;
        
        while(left < right) {
            int temp = min(height[left], height[right]) * (right-left);
            if(temp > max) {
                max = temp;
            }
            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max;
    }
    
    
};

int main() {
    vector<int> v = {1,8,6,2,5,4,8,3,7};
    Solution s;
    cout << s.maxArea(v) << endl;
    cout << s.others(v) << endl;
}
