//
//  29DivideTwoIntegers.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/2.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、借助a/b = e^(ln(a))/e^(ln(b)) = e^(ln(a)-ln(b))，4ms，8.4MB
    int divide(int dividend, int divisor) {
        if (dividend==0) return 0;
        if (divisor==0) return INT_MAX;
        long long res=double(exp(log(fabs(dividend))-log(fabs(divisor))));
        if ((dividend<0)^(divisor<0)) res=-res;
        if (res>INT_MAX) res=INT_MAX;
        return res;
    }
};
