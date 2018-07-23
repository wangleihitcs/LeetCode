//
//  28Implement strStr.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/7/23.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <time.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        int haystack_length = haystack.size();
        int needle_length = needle.size();
        if((haystack_length < needle_length)) return -1;
        for(int i=0; i <= haystack_length-needle_length; i++) {
            if(haystack[i] == needle[0]){
                bool flag = true;
                for(int j=0; j < needle_length; j++) {
                    if(haystack[i+j] != needle[j]) {
                        flag=false;
                        break;
                    }
                }
                if(flag) return i;
            }
        }
        return -1;
    }
    
    int others(string haystack, string needle) {
        if(needle=="") return 0;
        int index = haystack.find(needle);
        if(index != haystack.npos) return index;
        return -1;
    }
};

int main() {
    string haystack = "hello";
    string needle = "ell";
    Solution s;
    cout << s.strStr(haystack, needle) << endl;
}
