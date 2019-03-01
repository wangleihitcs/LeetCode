//
//  10fibonacci.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/1.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、递归，时间复杂度O(2^n)
    int Fibonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        return Fibonacci(n-2) + Fibonacci(n-1);
    }
    
    //方法二、记录前面的斐波那契数列，时间复杂度O(n)，3ms, 492k
    int Fibonacci2(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int res = -1;
        int fibOne = 0, fibTwo = 1;
        for(int i = 2; i <= n; i++) {
            res = fibOne + fibTwo;
            fibOne = fibTwo;
            fibTwo = res;
        }
        return res;
    }
};

int main() {
    Solution s;
    int n = 40;
    cout << s.Fibonacci2(n) << endl;
    cout << s.Fibonacci(n) << endl;
}
