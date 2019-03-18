//
//  58leftRotateString.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/18.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、精妙算法，时间复杂度O(n)，空间复杂度O(1)
    string LeftRotateString(string str, int n) {
        if(str.size() <= 0 || n <= 0) return str;
        int m = n % str.size();
        reverse(str, 0, str.size() - 1);
        reverse(str, 0, str.size() - m - 1);
        reverse(str, str.size() - m, str.size() - 1);
        return str;
    }
    //时间复杂度O(n)
    void reverse(string& str, int left, int right) {
        while(left < right) {
            char ch = str[left];
            str[left] = str[right];
            str[right] = ch;
            left++;
            right--;
        }
    }
};

int main() {
    Solution s;
    string str = "abcXYZdef";
    cout << str << endl;
    cout << s.LeftRotateString(str, 1) << endl;
}
