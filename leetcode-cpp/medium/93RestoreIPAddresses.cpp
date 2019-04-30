//
//  93RestoreIPAddresses.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/19.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、回溯法，时间复杂度O(2^n)，空间复杂度O(2^n)，8ms，8.7MB
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        backtrack(s, 4, "", res);
        return res;
    }
    void backtrack(string s, int k, string out, vector<string> &res) {
        if (k == 0) {
            if (s.empty()) res.push_back(out);
        } else {
            for (int i = 1; i <= 3; i++) {
                if (s.size() >= i && isValid(s.substr(0, i))) {
                    if(k == 1) {
                        backtrack(s.substr(i), k - 1, out + s.substr(0, i), res);
                    } else {
                        backtrack(s.substr(i), k - 1, out + s.substr(0, i) + ".", res);
                    }
                }
            }
        }
    }
    bool isValid(string s) {
        if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0')) return false;
        int res = atoi(s.c_str());
        return res <= 255 && res >= 0;
    }
};

int main() {
    string s = "255255255255";
    Solution so;
    vector<string> res = so.restoreIpAddresses(s);
    for(string str : res) {
        cout << str << endl;
    }
}
