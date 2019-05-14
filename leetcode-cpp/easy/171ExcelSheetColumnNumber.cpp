//
//  171ExcelSheetColumnNumber.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/5/5.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    //方法一、26进制，时间复杂度O(n)，空间复杂度O(1)，4ms，8.3MB
    int titleToNumber(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            res += (s[i] - 'A' + 1) * pow(26, s.size() - 1 - i);
        }
        return res;
    }
    
    //方法二、一的改进，4ms，8.1MB
    int titleToNumber2(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            res *= 26;
            res += s[i] - 'A' + 1;
        }
        return res;
    }
};
