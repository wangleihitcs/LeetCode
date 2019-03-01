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
    //方法一: O(n!), right but time limit, 递归
    string longestPalindrome1(string s) {
        if(isPalindrome(s) == true) return s;
        int length = s.size();
        string s_left = longestPalindrome1(s.substr(0, length-1));
        string s_right =  longestPalindrome1(s.substr(1, length-1));
        if(s_left.size() > s_right.size()) {
            return s_left;
        } else {
            return s_right;
        }
    }
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
    
    //方法二: O(n*n*n*n), 公共最长子串变形, time limit
    string longestPalindrome2(string s) {
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
    
    //方法三: O(n^2), expand around center
    string longestPalindrome3(string s) {
        if(s.size() <= 1) return s;
        int start = 0, end = 0;
        int longest = 0;
        for(int i = 0; i < s.size(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i+1);
            int len = len1 > len2 ? len1 : len2;
            if(len > longest) {
                start = i - (len - 1)/2;
                end = i + len/2;
                longest = len;
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
        while(L >= 0 && R < s.size() && s[L] == s[R]) {
            R++;
            L--;
        }
        return R - L - 1;   //  注意边界
    }
    
    //方法四: O(n^2), 动态规划求公共最长子串
    // P[i+1][j-1] = True, if S[i, j]为回文而且S[i] == S[j]
    string longestPalindrome4(string s) {
        if(s.size() <= 1) return s;
        int n = s.size();
        vector<vector<int>> P(n, vector<int>(n));
        
        //1.构造辅助数组P
        for(int i = 0; i < n; i++) {
            P[i][i] = 1;
            if(s[i] == s[i+1] && i < n-1) P[i][i+1] = 1;
        }
        for(int i = 0; i < n-1; i++) {
            for(int j = 1; j < n; j++) {
                if(s[i+1] == s[j-1] && P[i][j] == 1) {
                    P[i+1][j-1] = 1;
                }
            }
        }
        
        //2.遍历得到最大回文子串
        int longest = 0;
        int start = 0, end = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(P[i][j] == 1) {
                    int len = abs(i-j) + 1;
                    if(len > longest) {
                        start = i < j ? i : j;
                        end = i > j ? i : j;
                        longest = len;
                    }
                }
            }
        }
        string result;
        cout << start << " " << end << " " << endl;
        for(int i = start; i <= end; i++) {
            result += s[i];
        }
        return result;
    }
};

int main() {
    Solution so;
    string s = "abcdefgkk";
    cout << so.longestPalindrome4(s) << endl;
//    cout << so.expandAroundCenter(s, 2, 2) << endl;
}
