//
//  168ExcelSheetColumnTitle.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/5/8.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、自然，时间复杂度O(n)，空间复杂度O(n)，4ms，8.1MB
    string convertToTitle(int n) {
        string res = "";
        while(n > 26) {
            if(n % 26 == 0) {
                res.insert(res.begin(), 'Z');
                n = n / 26 - 1;
            } else {
                res.insert(res.begin(), (char)('A' + n % 26 - 1));
                n = n / 26;
            }
        }
        res.insert(res.begin(), (char)('A' + n - 1));
        return res;
    }
};

int main() {
    Solution s;
    cout << 701 % 26 << endl;
    cout << s.convertToTitle(701) << endl;
}
