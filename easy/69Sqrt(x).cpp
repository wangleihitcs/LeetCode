//
//  69Sqrt(x).cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/8/10.
//  Copyright © 2018年 wanglei. All rights reserved.
//

#include <iostream>
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
    int others1(int x) {
        int l = 1, r = x;
        while(l <= r) {
            int mid = (l + r)/2;
            if(mid * mid > x) r = mid - 1;
            else l = mid + 1;
        }
        return l - 1;
    }
    
    int others2(int x) {
        int i = 0;
        unsigned int term = 1;
        unsigned int sum = 1;
        while(sum <= x){
            ++i;
            term += 2;
            sum += term;
        }
        return i;
    }
};

int main() {
    Solution s;
//    cout << s.mySqrt(1) << endl;
    cout << s.others1(2147395599) << endl;
}
