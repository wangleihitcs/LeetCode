//
//  88MergeSortedArray.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/10/22.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、O(m+n), 最简单的，逐个逐个比较
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(nums1[i] <= nums2[j]) {
                result.push_back(nums1[i]);
                i++;
            } else {
                result.push_back(nums2[j]);
                j++;
            }
        }
        if(i < m) {
            for(int p = i; p < m; p++) {
                result.push_back(nums1[p]);
            }
        }
        if(j < n) {
            for(int p = j; p < n; p++) {
                result.push_back(nums2[p]);
            }
        }
        nums1 = result;
    }
};

int main() {
    vector<int> nums1 = {1,2,5,7,0,0,0};
    vector<int> nums2 = {4,12,13};
    Solution s;
    s.merge(nums1, 4, nums2, 3);
    for(int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
}
