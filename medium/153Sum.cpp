//
//  153Sum.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/8/2.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //O(n^3), 超时
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        if(nums.size() < 3) return result;
        for(int i = 0; i < nums.size()-2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < nums.size()-1; j++) {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                for(int k = j+1; k < nums.size(); k++) {
                    if(k > j+1 && nums[k] == nums[k-1]) continue;
                    if(nums[i]+nums[j]+nums[k] == 0) {
                        result.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        return result;
    }
    
    //O(n^2)
    vector<vector<int>> others(vector<int>& nums) {
        vector<vector<int>> ans;
        int l, r, m, N, sum;
        sort(nums.begin(), nums.end());
        N = nums.size();
        
        l = 0;
        while (l < N-2) {
            if (l != 0 && (nums[l] > 0 || nums[l] == nums[l-1])){
                l++; continue;
            }
            
            m = l+1; r = N-1;
            while (m < r) {
                sum = nums[l] + nums[m] + nums[r];
                if (sum == 0)
                    ans.push_back({nums[l], nums[m], nums[r]});
                if (sum <= 0) {
                    m++;
                    while((nums[m] == nums[m-1]) && m < r)
                        m++;
                }
                if (sum >= 0) {
                    r--;
                    while((nums[r] == nums[r+1]) && m < r)
                        r--;
                }
            }
            l++;
        }
        return ans;
    }
    
};

int main() {
    vector<int> v = {0, 0, 0, 0, 0, 0, -1, 1, 0};
    Solution s;
    vector<vector<int>> result = s.others(v);
    for(vector<vector<int>>::iterator it = result.begin(); it != result.end(); it++) {
        vector<int> temp = *(it);
        for(vector<int>::iterator it2 = temp.begin(); it2 != temp.end(); it2++) {
            cout << *(it2) << " ";
        }
        cout << endl;
    }
}
