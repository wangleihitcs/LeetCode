//
//  10RegularExpressionMatching.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/25.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、递归，时间复杂度O((n+m)*2^(n+m/2))，空间复杂度一样，216ms，15.7MB
    bool isMatch(string s, string p) {
        if(s.size() == 0 && p.size() == 0) return true;
        //判断第一个字符是否匹配
        bool firstMatch = !p.empty() && !s.empty() && (p[0] == s[0] || p[0] == '.');
        if(p.size() >= 2 && p[1] == '*') {//*表示0或者多个
            return isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p));
        } else {
            return firstMatch && isMatch(s.substr(1), p.substr(1));
        }
    }
    
    //方法二、dp，时间复杂度O(mn)，空间复杂度O(mn)，8ms，9.1MB
    //dp[i][j] = dp[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
    //dp[i][j] = dp[i][j - 2], if p[j - 1] == '*', 重复0次;
    //dp[i][j] = dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*'，重复一次.
    bool isMatch2(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    string s = "aaaa";
    string p = "a*";
    Solution so;
    cout << so.isMatch2(s, p) << endl;
}
