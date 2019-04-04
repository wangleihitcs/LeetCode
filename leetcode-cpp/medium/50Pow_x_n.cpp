//
//  50Pow_x_n.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/4.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、暴力，时间复杂度O(n)，空间复杂度O(1)，time limited
    double myPow(double x, int n) {
        double res = 1.0;
        if(n > 0) {
            for(int i = 0; i < n; i++) {
                res *= x;
            }
        } else if(n == 0) {
            res = 1.0;
        } else {
            for(int i = 0; i < -n; i++) {
                res *= 1/x;
            }
        }
        return res;
    }
    
    //方法二、公式，时间复杂度O(logn)，空间复杂度O(1)，time limited
    //x^n = x^(n/2) * x^(n/2) * x，n为奇数; n > 0;
    //x^n = x^(n/2) * x^(n/2)，n为偶数
    double myPow2(double x, int n) {
        if(n == 0) return 1;
        if(n < 0) {
            n = -n;
            x = 1.0 / x;
        }
        if(n % 2 == 0) {
            return myPow2(x, n / 2)*myPow2(x, n / 2);
        } else {
            return myPow2(x, n / 2)*myPow2(x, n / 2) * x;
        }
    }
    
    //方法三、公式，时间复杂度O(logn)，空间复杂度O(1)，4ms，8.4MB
    double myPow3(double x, int n) {
        if(n<0) return 1/x * myPow3(1/x, -(n+1));
        if(n==0) return 1;
        if(n==2) return x*x;
        if(n%2==0) return myPow3(myPow3(x, n/2), 2);
        else return x*myPow3(myPow3(x, n/2), 2);
    }
};

int main() {
    Solution s;
    cout << s.myPow2(2.0, -2) << endl;
}
