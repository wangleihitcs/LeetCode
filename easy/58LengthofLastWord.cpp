//
//  58LengthofLastWord.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/7/30.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        for(int j = s.size()-1; j >= 0; j--) {
            if(s[j] == ' ') {
                continue;
            } else {
                length++;
            }
            if(length > 0 && j == 0) return length;
            if(length > 0 && s[j-1] == ' ') return length;
        }
        return length;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLastWord("    zzz") << endl;
}
