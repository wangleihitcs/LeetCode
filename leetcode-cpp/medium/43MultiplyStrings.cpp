//
//  43MultiplyStrings.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/3.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、找规律，时间复杂度O(m+n)，空间复杂度O(m+n)
    string multiply(string num1, string num2) {
        string sum(num1.size() + num2.size(), '0');
        
        for(int i = num1.size() - 1; i >= 0; i--) {
            int carry = 0;
            for(int j = num2.size() - 1; j >= 0; j--) {
                int temp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                sum[i + j + 1] = temp % 10 + '0';
                carry = temp / 10;
            }
            sum[i] += carry;
        }
        int i = 0;
        for(i = 0; i < num1.size() + num2.size(); i++) {
            if(sum[i] != '0') {
                return sum.substr(i);
            }
        }
        return "0";
    }
};

int main() {
    string num1 = "3";
    string num2 = "2";
    Solution s;
    cout << s.multiply(num1, num2) << endl;
    char c = 2 + '0';
    cout << c << endl;
}
