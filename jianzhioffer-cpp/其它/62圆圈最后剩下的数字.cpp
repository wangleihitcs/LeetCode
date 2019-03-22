//
//  62lastRemaining.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/22.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一，按照规则找规律
    int LastRemaining(int n, int m) {
        if(n < 1 || m < 1) return -1;
        //1.构建数组
        vector<int> v;
        for(int i = 0; i < n; i++) {
            v.push_back(i);
        }
        
        //2.模拟圆圈
        int last = 0;
        while(v.size() > 1) {
            last = (last + m - 1) % v.size();
            v.erase(v.begin() + last);
        }
        
        return v[0];
    }
    
    //方法二、动态规划
    int LastRemaining2(int n, int m) {
        if(n < 1 || m < 1) return -1;
        int last = 0;
        for(int i = 2; i <= n; i++) {
            last = (last + m) % i;
        }
        return last;
    }
};

int main() {
    Solution s;
    cout << s.LastRemaining(100, 17) << endl;
    cout << s.LastRemaining2(100, 17) << endl;
}
