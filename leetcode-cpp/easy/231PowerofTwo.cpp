//
//  231PowerofTwo.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/6/4.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <cmath>

class Solution {
public:
    //方法一、借助pow，平均时间复杂度O(logn)，空间的复杂度O(1)，4ms，8.5MB
    bool isPowerOfTwo(int n) {
        for(int i = 0; i <= n; i++) {
            if(pow(2, i) == n) return true;
            if(pow(2, i) > n) break;
        }
        return false;
    }
    
    //方法二、巧妙，最坏时间复杂度O(logn)，空间复杂度O(1)，0ms，8.2MB
    bool isPowerOfTwo2(int n) {
        if(n == 0) return false;
        if(n == 1) return true;
        while(n % 2 == 0) {
            n = n / 2;
            if(n == 1) return true;
        }
        return false;
    }
};
