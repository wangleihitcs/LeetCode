//
//  14numberOf1.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/2.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、常规解法，4ms，循环了32次
    //二进制正数右移一位，最高位补0；负数右移一位，最高位补1
    int NumberOf1(int n) {
        int count = 0;
        unsigned int flag = 1;
        while(flag) {
            if(n & flag)
                count++;
            flag = flag << 1;
        }
        return count;
    }
    
    //方法二、技巧
    int NumberOf12(int n) {
        int count = 0;
        while (n) {
            count++;
            n = (n-1) & n;
        }
        return count;
    }
};

int main() {
    Solution s;
    cout << s.NumberOf1(-9) << endl;
}
