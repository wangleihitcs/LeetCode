//
//  64sum.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/20.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、公式，输入的是正整数且范围不超界
    int Sum(int n) {
        return n*(n+1) / 2;
    }
    //方法二、直接累加
    int Sum2(int n) {
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += i;
        }
        return sum;
    }
    //方法三、递归的思想，不使用乘法除法，循环
    int Sum3(int n) {
        if(n == 1) return 1;
        return Sum3(n-1) + n;
    }
    //方法四、递归思想，虚函数，不使用乘法除法，循环，if else、switch case等判断语句
};

int main() {
    Solution s;
    cout << s.Sum3(5) << endl;
}
