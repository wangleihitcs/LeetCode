//
//  3LongestSubstringWithoutRepeatingCharacters.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/7/24.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        vector<char> v;
        int max = 1;
        for(int k = 0; k < s.size() - max; k++) {
            v.push_back(s[k]);
            bool flag = true;
            for(int i = k+1; i < s.size(); i++) {
                for(vector<char>::iterator it = v.begin(); it != v.end(); it++) {
                    if(*(it) == s[i]) {
                        flag = false;
                        break;
                    }
                }
                if(flag == true) {
                    v.push_back(s[i]);
                } else {
                    break;
                }
            }
            if(v.size() > max) max = v.size();
            if(flag == false) v.clear();
        }
        
        return max;
    }
    
    int others(string s) {
        vector<int> dict(256, -1);  //包含256个值为1的元素
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        cout << dict['c'] << endl;
        return maxLen;
    }
};

int main() {
    string str = "cabcaa";
    Solution s;
//    cout << s.lengthOfLongestSubstring(str) << endl;
    cout << s.others(str) << endl;
}
