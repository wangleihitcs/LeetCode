//
//  70ClimbingStairs.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/9/5.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    // O(n)
    int climbStairs(int n) {
        if(n <= 2) return n;
        int fn_2 = 1, fn_1  = 2;
        int fn = 0;
        for(int i = 3; i <= n; i++) {
            fn = fn_2 + fn_1;
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn;
    }
};

int main() {
    int n = 5;
    Solution s;
    cout << s.climbStairs(4) << endl;
}
