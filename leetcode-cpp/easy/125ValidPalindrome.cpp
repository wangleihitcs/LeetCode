//
//  125ValidPalindrome.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/21.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、双指针，时间复杂度O(n)，空间复杂度O(1)，12ms，9.3MB
    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while(l < r && isDigistAndCharacter(s[l]) == false)
                l++;
            while(l < r && isDigistAndCharacter(s[r]) == false)
                r--;
            if(l <= r && tolower(s[l]) == tolower(s[r])) {
                l++;
                r--;
            } else {
                return false;
            }
        }
        return true;
    }
    bool isDigistAndCharacter(char c) {
        if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
        return false;
    }
};

int main() {
    string s = "a Man, a plan, a canal: panama";
    Solution so;
    cout << so.isPalindrome(s) << endl;
}
