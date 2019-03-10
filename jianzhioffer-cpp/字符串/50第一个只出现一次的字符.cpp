//
//  50firstNotRepeatingChar.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/7.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    //方法一、暴力解法，时间复杂度O(n)，时间复杂度O(1)
    int FirstNotRepeatingChar(string str) {
        map<char, int> m1;  //store index
        map<char, int> m2;  //store count
        for(int i = 0; i < str.size(); i++) {
            if(m1.find(str[i]) == m1.end()) {
                m1.insert(pair<char, int>(str[i], i));
                m2.insert(pair<char, int>(str[i], 1));
            } else {
                m2[str[i]] += 1;
            }
        }
        
        map<char, int>::iterator it;
        int min = str.size();
        for(it = m2.begin(); it != m2.end(); it++) {
            if(it ->second == 1 && m1[it ->first] < min) {
                min = m1[it ->first];
            }
        }
        if(min >= 0 && min < str.size()) return min;
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.FirstNotRepeatingChar("google") << endl;
}

