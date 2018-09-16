//
//  5LongestPalindromicSubstring.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/9/11.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math>
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
    //O(n^2), expand around center
    string longestPalindrome2(string s) {
        if(s.size() <= 1) return s;
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = len1 > len2 ? len1 : len2;
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        string result;
        cout << start << " " << end << " " << endl;
        for(int i = start; i <= end; i++) {
            result += s[i];
        }
        return result;
    }
    int expandAroundCenter(string s, int left, int right) {
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s[L] == s[R]) {
            L--;
            R++;
        }
        return R - L - 1;
    }
    
    
};

int main() {
    Solution so;
    string s = "aacdefcaa";
    cout << so.longestPalindrome2(s) << endl;
}
