//
//  5LongestPalindromicSubstring.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/9/11.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //O(n!), right but time limit
    string longestPalindrome(string s) {
        if(isPalindrome(s) == true) return s;
        int length = s.size();
        string s_left = longestPalindrome(s.substr(0, length-1));
        string s_right =  longestPalindrome(s.substr(1, length-1));
        if(s_left.size() > s_right.size()) {
            return s_left;
        } else {
            return s_right;
        }
    }
    
    //O(n/2)
    bool isPalindrome(string s) {
        if(s.size() <= 1) return true;
        int left = 0, right = s.size()-1;
        while(left < right) {
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    
    //O(n*n*n*n), 公共最长子串变形, time limit
    string longestPalindrome1(string s) {
        if(s.size() <= 1) return s;
        string s_tran = s;
        for(int i = 0; i < s.size(); i++) {
            s_tran[i] = s[s.size()-1-i];
        }
        int longest = 0;
        int start1 = -1, start2 = -1;
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < s_tran.size(); j++) {
                int length = 0;
                int m = i;
                int n = j;
                while(m < s.size() && n < s_tran.size()) {
                    if(s[m] != s_tran[n]) break;
                    length++;
                    m++;
                    n++;
                }
                if(longest < length) {
                    string temp;
                    for(int z = i; z < m; z++) {
                        temp += s[z];
                    }
                    if(isPalindrome(temp) == true) {
                        longest = length;
                        start1 = i;
                        start2 = m;
                    }
                }
            }
        }
        string result;
        cout << start1 << " " << start2 << " " << longest << endl;
        for(int i = start1; i < start2; i++) {
            result += s[i];
        }
        return result;
    }
    
};

int main() {
    Solution so;
    string s = "aacdefcaa";
    cout << so.longestPalindrome1(s) << endl;
}
