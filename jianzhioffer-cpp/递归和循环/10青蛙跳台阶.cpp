//
//  10jumpFloor.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/15.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //简单版，青蛙一次只能跳1级或者2级
    int jumpFloor(int number) {
        if(number == 1) return 1;
        if(number == 2) return 2;
        return jumpFloor(number-2) + jumpFloor(number-1);
    }
    
    //变态版，青蛙一次只能跳1级或者2级或者ni级
    int jumpFloorII(int number) {
        if(number == 1) return 1;
        if(number == 2) return 2;
        int res = 0;
        for(int i = 1; i < number; i++) {
            res += jumpFloorII(i);
        }
        return res + 1;
    }
};

int main() {
    Solution s;
    cout << s.jumpFloorII(4) << endl;
}
