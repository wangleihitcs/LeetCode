//
//  69Sqrt(x).cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/8/10.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    // O(n), time limit
    int mySqrt(int x) {
        for(int i = 1; i <= x; i++) {
            if(i*i == x) {
                return i;
            } else if(i*i < x && (i+1)*(i+1) > x) {
                return i;
            }
        }
        return 0;
    }
    
    // O(log(n)), time limit
    int SqrtByBisection(int x) {
        int left = 0, right = x;
        int mid = (left + right)/2;
        int last_mid;
        float eps = 0.01;
        do {
            if(mid * mid <= x) {
                left = mid;
            } else {
                right = mid;
            }
            last_mid = mid;
            mid = (left + right)/2;
        } while(abs(mid - last_mid) > eps);
        return mid;
    }
    float SqrtByBisection2(float x) {
        float left = 0, right = x;
        while(right - left > 0.01) {
            float mid = (left + right)/2;
            if(mid * mid <= x)
                left = mid;
            else
                right = mid;
        }
        return left;
    }
    
    // O(), accepted, time limit
    int SqrtByNewton(int x) {
        if(x == 0) return 0;
        if(x == 1) return 1;
        unsigned int x0 = x;
        int last;
        do {
            last = x0;
            x0 = (x0 + x/x0)/2;
            cout << last << " " << x0 << endl;
        } while(last - x0 > 0.01);

        return last;
    }
};

int main() {
    int x = 2147483647;
    
    Solution s;
//    cout << s.mySqrt(101) << endl;
//    cout << s.SqrtByBisection(1001) << endl;
//    cout << s.SqrtByBisection2(1001) << endl;
    cout << s.SqrtByNewton(2147483647) << endl;
    cout << "sqrt() " << (int)sqrt(x) << endl;
}
