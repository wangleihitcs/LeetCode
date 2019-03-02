//
//  16power.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/2.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、考虑全面
    //指数为正数
    //指数为负数
    //指数为0
    double Power(double base, int exponent) {
        if(base == 0.0 && exponent < 0) {//不合法，0不能做分母
            cout << "不合法" << endl;
            return 0;
        }
        if(exponent == 0) return 1;
        double res = 1.0;
        if(exponent > 0) {
            for(int i = 1; i <= exponent; i++) {
                res *= base;
            }
        }
        if(exponent < 0) {
            for(int i = exponent; i <= -1; i++) {
                res *= base;
            }
            res =  1.0 / res;
        }
        return res;
    }
    
    //方法二、优化，时间复杂度O(logn)
    //a^n = a^(n-1)/2 * a^(n-1)/2，n为偶数
    //a^n = a^(n-1)/2 * a^(n-1)/2 * a，n为奇数
    double Power2(double base, int exponent) {
//        if(base == 0.0 && exponent < 0) {//不合法，0不能做分母
//            cout << "不合法" << endl;
//            return 0;
//        }
        if(exponent == 0) return 1;
        if(exponent == 1) return base;
        if(exponent == -1) return 1.0 / base;
        
        double res = Power2(base, (exponent-1)/2);
        res *= res;
        if(exponent % 2 != 0)
            res *= base;
        return res;
    }
};

int main() {
    Solution s;
    cout << s.Power(-5, -3) << endl;
    cout << s.Power2(-5, -3) << endl;
}
