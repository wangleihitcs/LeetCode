//
//  67strToInt.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/20.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、要充分考虑各种情况
    int StrToInt(string str) {
        if(str == "") return 0;
        bool isPositive = true;
        if(str[0] == '+' || str[0] == '-') {
            if(str[0] == '-') isPositive = false;
            str = str.substr(1, str.size());
        }
        if(str == "") return 0;
        int num = 0;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] >= '0' && str[i] <= '9') {
                num = num * 10 + (str[i] - '0');
            } else {
                return 0;
            }
        }
        if(!isPositive) return 0 - num;
        return num;
    }
    
};

int main() {
    string str = "2147483647";
//    cout << str.substr(1, str.size()) << endl;
    
    Solution s;
    cout << s.StrToInt(str) << endl;
}
