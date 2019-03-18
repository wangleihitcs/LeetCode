//
//  10rectCover.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/15.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int rectCover(int number) {
        if(number == 1) return 1;
        if(number == 2) return 2;
        return rectCover(number - 1) + rectCover(number - 2);
    }

    int rectCover2(int number) {
        if(number == 0) return 0;
        if(number == 1) return 1;
        if(number == 2) return 2;
        
        int ai_1 = 2, ai_2 = 1;
        int ai = 3;
        for(int i = 3; i <= number; i++) {
            ai = ai_1 + ai_2;
            ai_2 = ai_1;
            ai_1 = ai;
        }
        return ai;
    }
};

int main() {
    Solution s;
    cout << s.rectCover2(5) << endl;
}
