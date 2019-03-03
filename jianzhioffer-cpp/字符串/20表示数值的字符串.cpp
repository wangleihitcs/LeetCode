//
//  20isNumeric.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/3.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isNumeric(char* string) {
        if(string == NULL) return false;
        bool isNum = scanInt(&string);
        if(*string == '.') {
            string++;
            //因为整数部分可以没有，如.123，因此isNum可以没有
            isNum = scanUnsignedInt(&string) || isNum ;
        }
        if(*string == 'E' || *string == 'e') {
            string++;
            //因为E前面不能没有数字，isNum必须存在
            isNum = isNum && scanInt(&string);
        }
        return isNum && *string == '\0';
    }
    
    bool scanInt(char** str) {
        if(**str == '+' || **str == '-') {
            (*str)++;
        }
        return scanUnsignedInt(str);
    }
    bool scanUnsignedInt(char** str) {
        char* current_ch = *str;
        while(**str != '\0' && **str >= '0' && **str <= '9') {
            (*str)++;
        }
        return *str > current_ch;
    }
};

int main() {
    Solution s;
    char* str = "+1E-16";
    cout << s.isNumeric(str) << endl;
}
