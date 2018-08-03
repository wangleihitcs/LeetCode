//
//  67AddBinary.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/8/3.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //O(max(n, m))
    string addBinary(string a, string b) {
        string result;
        int i = a.size() - 1, j = b.size() - 1;
        int carry_flag = 0;
        vector<char> v;
        for(; i >= 0 && j >= 0; i--, j--) {
            if(a[i] - '0' + b[j] - '0' + carry_flag < 2) {
                v.insert(v.begin(), a[i] - '0' + b[j] - '0' + carry_flag + '0');
                carry_flag = 0;
            } else {
                v.insert(v.begin(), a[i] - '0' + b[j] - '0' + carry_flag - 2 + '0');
                carry_flag = 1;
            }
        }
        if(i >= 0) {
            while(i >= 0) {
                if(a[i] - '0' + carry_flag < 2) {
                    v.insert(v.begin(), a[i] - '0' + carry_flag + '0');
                    carry_flag = 0;
                } else {
                    v.insert(v.begin(), a[i] - '0' + carry_flag - 2 + '0');
                    carry_flag = 1;
                }
                i--;
            }
        }
        if(j >= 0) {
            while(j >= 0) {
                if(b[j] - '0' + carry_flag < 2) {
                    v.insert(v.begin(), b[j] - '0' + carry_flag + '0');
                    carry_flag = 0;
                } else {
                    v.insert(v.begin(), b[j] - '0' + carry_flag - 2 + '0');
                    carry_flag = 1;
                }
                j--;
            }
        }
        if(carry_flag == 1) {
            v.insert(v.begin(), carry_flag + '0');
        }
        for(vector<char>::iterator it = v.begin(); it != v.end(); it++) {
            result += *(it);
        }
        return result;
    }
};

int main() {
    string a = "1", b = "111111111";
    Solution s;
    cout << s.addBinary(a, b) << endl;
}
