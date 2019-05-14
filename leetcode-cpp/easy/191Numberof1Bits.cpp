//
//  191Numberof1Bits.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/5/9.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、32位一个一个比，时间复杂度O(1)，空间复杂度O(1)，4ms，8.4MB
    int hammingWeight(uint32_t n) {
        int res = 0;
        for(int i = 0; i < 32; i++) {
            if((n & (1 << i)) != 0) res++;
        }
        return res;
    }
    
    //方法二、位运算，时间复杂度O(1)，空间复杂度O(1)，4ms，8.3MB
    int hammingWeight2(uint32_t n) {
        int res = 0;
        while(n != 0) {
            res++;
            n = n & (n-1);
        }
        return res;
    }
    
    //方法三、库函数，4ms，8.4MB
    int hammingWeight3(uint32_t n) {
        return bitset<32>(n).count();
    }
};


