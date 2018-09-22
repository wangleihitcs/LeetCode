//
//  12IntegertoRoman.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/9/22.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    //O(4), 1 <= m << 3999
    string intToRoman(int num) {
        //1. init map
        map<int, string> map = getMap();
        
        //2. 计算出千位、百位、十位、个位
        string result = "";
        int m = num / 1000;
        if(m != 0) result += map[m*1000];
        int c = (num - 1000*m) / 100;
        if(c != 0) result += map[c*100];
        int x = (num - 1000*m - 100*c) / 10;
        if(x != 0) result += map[x*10];
        int i = num - 1000*m - 100*c - 10*x;
        if(i != 0) result += map[i];
        
        return result;
    }
    
    map<int, string> getMap() {
        map<int, string> map;
        map[1] = "I";
        map[2] = "II";
        map[3] = "III";
        map[4] = "IV";
        map[5] = "V";
        map[6] = "VI";
        map[7] = "VII";
        map[8] = "VIII";
        map[9] = "IX";
        
        map[10] = "X";
        map[20] = "XX";
        map[30] = "XXX";
        map[40] = "XL";
        map[50] = "L";
        map[60] = "LX";
        map[70] = "LXX";
        map[80] = "LXXX";
        map[90] = "XC";
        
        map[100] = "C";
        map[200] = "CC";
        map[300] = "CCC";
        map[400] = "CD";
        map[500] = "D";
        map[600] = "DC";
        map[700] = "DCC";
        map[800] = "DCCC";
        map[900] = "CM";
        
        map[1000] = "M";
        map[2000] = "MM";
        map[3000] = "MMM";
        
        return map;
    }
};

int main() {
    Solution so;
    cout << so.intToRoman(4) << endl;
}
