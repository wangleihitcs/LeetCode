//
//  57continuousSequence.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/15.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        if(sum <= 2) return res;
        
        int left = 1, right = 2;
        int mid = (1 + sum) / 2;
        int curSum = left + right;
        while(left < mid) {
            if(curSum == sum) {
                vector<int> item;
                for(int i = left; i <= right; i++) {
                    item.push_back(i);
                }
                res.push_back(item);
            }
            while(curSum > sum && left < mid) {
                curSum -= left;
                left++;
                if(curSum == sum) {
                    vector<int> item;
                    for(int i = left; i <= right; i++) {
                        item.push_back(i);
                    }
                    res.push_back(item);
                }
            }
            right++;
            curSum += right;
        }
        
        return res;
    }
};

int main() {
    Solution s;
    s.FindContinuousSequence(9);
}

