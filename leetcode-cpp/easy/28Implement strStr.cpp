//
//  28Implement strStr.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/7/23.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <time.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、暴力匹配，时间复杂度O(mn)，空间复杂度O(1)
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
    
    //方法二、KMP算法，时间复杂度O(n+m)，空间复杂度O(m)
    int KMP(string haystack, string needle) {
        if(needle == "") return 0;
        int N = haystack.size();
        int M = needle.size();
        if(N < M) return -1;
        
        vector<int> next(M, 0);
        getNext(needle, next);
        
        int i = 0, j = 0;
        while(i < N && j < M) {
            if(haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if(j != 0) j = next[j-1];
                else
                    i++;
            }
        }
        
        if(j == M) return i - j;
        
        return -1;
    }
    void getNext(string P, vector<int>& next) {
        int i, k;
        int M = P.size();
        next[0] = 0;
        for(i = 1, k = 0; i < M; i++) {
            while(k > 0 && P[i] != P[k])
                k = next[k-1];
            if(P[i] == P[k]) {
                k++;
            }
            next[i] = k;
        }
    }
};

int main() {
    string haystack = "helloaabcabc";
    string needle = "abcabc";
    Solution s;
    cout << s.KMP(haystack, needle) << endl;
}
