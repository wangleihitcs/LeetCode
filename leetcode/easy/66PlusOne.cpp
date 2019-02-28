//
//  66PlusOne.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/7/30.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> v;
        int carry_flag = 1;
        for(int j = digits.size()-1; j >= 0; j--) {
            int temp = digits[j] + carry_flag;
            if(temp < 10) {
                v.insert(v.begin(), temp);
                carry_flag = 0;
            } else {
                v.insert(v.begin(), 0);
                carry_flag = 1;
            }
        }
        if(carry_flag == 1) v.insert(v.begin(), 1);;
        return v;
    }
};

int main() {
    vector<int> v = {9, 9, 9, 9};
    Solution s;
    vector<int> result = s.plusOne(v);
    for(vector<int>::iterator it = result.begin(); it != result.end(); it++) {
        cout << *(it) << " ";
    }
}
