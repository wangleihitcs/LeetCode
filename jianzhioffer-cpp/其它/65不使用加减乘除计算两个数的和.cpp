//
//  65twoSum.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/20.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、使用二进制运算
    int Add(int num1, int num2) {
        int sum, carry;
        do {
            sum = num1 ^ num2;
            carry = (num1 & num2) << 1;
            num1 = sum;
            num2 = carry;
        } while(num2 != 0);
        return num1;
    }
};

int main() {
    Solution s;
    cout << s.Add(19, 199) << endl;
}
