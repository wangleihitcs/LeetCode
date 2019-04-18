//
//  89GrayCode.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/15.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、时间复杂度O(2^n)，空间复杂度O(2^n)，4ms，8.5MB
    vector<int> grayCode(int n) {
        vector<int> res(1, 0);
        for (int i = 0; i < n; i++) {
            int curCount = res.size();
            while (curCount) {
                curCount--;
                int curNum = res[curCount];
                curNum += (1 << i);
                res.push_back(curNum);
            }
        }
        return res;
    }
};

int main() {
    vector<int> res;
    Solution s;
    res = s.grayCode(2);
    cout << (1 << 1) << endl;
}
