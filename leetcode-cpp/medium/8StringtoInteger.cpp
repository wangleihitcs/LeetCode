//
//  8StringtoInteger.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/3/28.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、暴力解法，时间复杂度O(n)
    //主要考虑4点
    //1.' '空格
    //2.符号
    //3.溢出
    //4.无效字符
    int myAtoi(string str) {
        if(str.size() <= 0) return 0;
        
        int sign = 1, i = 0;
        long base = 0;
        while(str[i] == ' ') i++;
        if(str[i] == '+' || str[i] == '-') {
            sign = 1 - 2 * (str[i++] == '-');
        }
        while(str[i] >= '0' && str[i] <= '9') {
            base = 10 * base + (str[i++] - '0');
            if(base * sign >= INT_MAX) return INT_MAX;
            if(base * sign <= INT_MIN) return INT_MIN;
        }
        
        return base * sign;
    }
};

int main() {
    string m = "-2147483648";
    Solution s;
    cout << s.myAtoi(m) << endl;
    cout << INT_MIN << endl;
    cout << INT_MAX << endl;
}
