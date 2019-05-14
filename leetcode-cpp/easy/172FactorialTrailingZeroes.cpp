//
//  172.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/5/6.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、先求出n的阶乘，再求0的个数，时间复杂度O(n)，空间复杂度O(1)
    
    //方法二、统计2、5的个数，时间复杂度O(k)，空间复杂度O(1)，4ms，8.2MB
    //因为2的个数肯定远大于5，所以只要统计5的个数
    //5^1意味着1个0，5^k意味着k个0
    int trailingZeroes(int n) {
        int res = 0;
        for(long long i = 5; n / i > 0; i *= 5) {
            res += (n / i);
        }
        return res;
    }
};
