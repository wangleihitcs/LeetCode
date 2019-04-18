//
//  91DecodeWays.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/17.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、dp，时间复杂度O(n!)，空间复杂度O(1)，time limited
    int numDecodings(string s) {
        if(checkValid(s) == false) return 0;
        return backtrack(s);
    }
    int backtrack(string s) {
        if(s.size() <= 1) return 1;
        
        if(s.back() == '0') return backtrack(s.substr(0, s.size()-2));
        if(s.size() >= 2 && (s.substr(s.size()-2, 2) >= "10" && s.substr(s.size()-2, 2) <= "26")) {
            return backtrack(s.substr(0, s.size()-1)) + backtrack(s.substr(0, s.size()-2));
        }
        return backtrack(s.substr(0, s.size()-1));
    }
    bool checkValid(string s) {
        if(s.size() == 0) return false;
        if(s[0] == '0') return false;
        for(int i = 0; i < s.size()-1; i++) {
            if(s[i] == '0' && s[i] == s[i+1]) return false;
        }
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == '0' && s[i-1] >= '3') return false;
        }
        return true;
    }
    
    //方法二、dp，时间复杂度O(n^2)，空间复杂度O(n)，4ms，8.2MB，
    int numDecodings2(string s) {
        if(checkValid(s) == false) return 0;
        vector<int> nums(s.size(), 1);
        if(s.size() == 1) return 1;
        if(s.size() >= 2 && s.substr(0, 2) >= "10" && s.substr(0, 2) <= "26") {
            if(s.substr(0, 2) != "10" && s.substr(0, 2) != "20") {
                nums[1] = 2;
            }
        }
        for(int i = 2; i < s.size(); i++) {
            string temp = s.substr(i-1, 2);
            if(temp >= "10" && temp <= "26") {
                if(temp == "10" || temp == "20") {
                    nums[i] = nums[i-2];
                } else {
                    nums[i] = nums[i-1] + nums[i-2];
                }
            } else {
                nums[i] = nums[i-1];
            }
        }
        return nums.back();
    }
    
};

int main() {
    string s = "1213";
    Solution so;
    cout << so.numDecodings2(s) << endl;
}
