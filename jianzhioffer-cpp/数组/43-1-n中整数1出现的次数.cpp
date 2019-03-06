//
//  44numOf1Between1AndN.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/5.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、暴力枚举，时间画复杂度O(n*k)，空间复杂度O(1)
    int NumberOf1Between1AndN(int n) {
        if(n <= 0) return 0;
        int num = 0;
        for(int i = 1; i <= n; i++) {
            num += getNum(i);
        }
        return num;
    }
    int getNum(int n) {
        int num = 0;
        while(n != 0) {
            if(n % 10 == 1) num++;
            n = n / 10;
        }
        return num;
    }
    
    //方法二、利用常识，时间画复杂度O(n)，空间复杂度O(1)
    int NumberOf1Between1AndN2(int n) {
        if(n <= 0) return 0;
        int num = 0;
        for(int i = 1; i <= n; i++) {
            num += getNum(i);
        }
        return num;
    }
    
    
    
};

int main() {
    Solution s;
    cout << s.NumberOf1Between1AndN(13) << endl;
}
