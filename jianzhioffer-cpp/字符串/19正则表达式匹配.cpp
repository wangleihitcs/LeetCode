//
//  19matchStr.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/3.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //原理很简单，就是递归
    bool match(char* str, char* pattern) {
        if(*str == '\0' && *pattern == '\0')
            return true;
        if(*str != '\0' && *pattern == '\0')
            return false;
        
        if (*(pattern+1) != '*') {//if the next character in pattern is not '*'
            if (*str == *pattern || (*str != '\0' && *pattern == '.'))
                return match(str + 1, pattern + 1);
            else
                return false;
        } else {//if the next character is '*'
            if (*str == *pattern || (*str != '\0' && *pattern == '.'))
                return match(str, pattern + 2) || match(str + 1, pattern);
            else //ingore x*, x mean not equal pattern
                return match(str, pattern + 2);
        }
    }
};

int main() {
    Solution s;
    char str[101] = "", pattern[101] = ".";
    cout << s.match(str, pattern) << endl;
    
}
