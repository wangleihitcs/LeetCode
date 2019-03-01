//
//  4MedianofTwoSortedArrays.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/7/25.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //O(m+n)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int i = 0, j = 0;
        int m = nums1.size(), n = nums2.size();
        while(i < m && j < n) {
            if(nums1[i] <= nums2[j]) {
                v.push_back(nums1[i]);
                i++;
            } else {
                v.push_back(nums2[j]);
                j++;
            }
        }
        if(i >= m) {
            for(int k = j; k < nums2.size(); k++) {
                v.push_back(nums2[k]);
            }
        }
        if(j >= n) {
            for(int k = i; k < nums1.size(); k++) {
                v.push_back(nums1[k]);
            }
        }
        if((m + n) % 2 == 0) {
            if(m+n == 0) return 0;
            return (double)(v[(m+n)/2-1] + v[(m+n)/2])/2;
        } else {
            return (double)(v[(m+n)/2]);
        }
    }
    
    //O(log(min(m, n)))
    double others(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n) {
            vector<int> temp = nums1; nums1 = nums2; nums2 = temp;
            int _temp = m; m = n; n = _temp;
        }
        
        int imin = 0, imax = m, half_len = (m+n+1)/2;
        while(imin <= imax) {
            int i = (imin + imax)/2;
            int j = half_len - i;
            if(i < m && nums2[j-1] > nums1[i]) {
                imin = i + 1;
            } else if(i > 0 && nums1[i-1] > nums2[j]) {
                imax = i - 1;
            } else {
                int max_left, min_right;
                if(i == 0) {
                    max_left = nums2[j-1];
                } else if(j == 0) {
                    max_left = nums1[i-1];
                } else {
                    max_left = max(nums1[i-1], nums2[j-1]);
                }
                if((m + n) % 2 == 1) return max_left;
                
                if(i == m) {
                    min_right = nums2[j];
                } else if(j == n) {
                    min_right = nums1[i];
                } else {
                    min_right = min(nums1[i], nums2[j]);
                }
                
                return (double) (max_left + min_right) / 2;
            }
        }
        return 0;
    }
};

int main() {
    vector<int> nums1 = {1};
    vector<int> nums2 = {};
    Solution s;
//    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    cout << s.others(nums1, nums2) << endl;
    
}
