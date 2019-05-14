//
//  202HappyNumber.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/5/14.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、定义，时间复杂度O(k)，空间复杂度O(1)，0ms，8.3MB
    //注意无限循环，这其实是数学问题，1和7经过逐位平方和之后为回到1，而2-9的其他数字会陷入无限循环
    bool isHappy(int n) {
        if(n <= 0) return false;
        int sum = 0;
        while(n != 0) {
            int d = n % 10;
            sum += d * d;
            n = n / 10;
        }
        if(sum == 1 || sum == 7) return true;
        if(sum >= 2 && sum <= 9) return false;
        return isHappy(sum);
    }
};

int main() {
    Solution s;
    cout << s.isHappy(1111) << endl;
}
