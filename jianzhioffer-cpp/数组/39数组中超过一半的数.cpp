//
//  39MoreThanHalfNum.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/4.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、投票法，时间复杂度(n)，空间复杂度O(1)
    //假设数组超过一半的数为1，则其余数字全为-1，最后数组和>0，说明存在超过一半的数
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() == 0) return 0;
        
        int res = numbers[0];
        int sum = 1;
        for(int i = 0; i < numbers.size(); i++) {
            if(sum == 0) {
                res = numbers[i];
                sum = 1;
            } else if(res == numbers[i]) {
                sum++;
            } else {
                sum--;
            }
        }
        if(!isMoreThanHalf(numbers, res)) {
            res = 0;
        }
        return res;
    }
    
    bool isMoreThanHalf(vector<int>& numbers, int res) {
        int time = 0;
        for(int i = 0; i < numbers.size(); i++) {
            if(res == numbers[i]) time++;
        }
        if(time > numbers.size()/2) return true;
        return false;
    }
};

int main() {
    vector<int> num = {1,1,2,3,4,1,1,2,1,2,2,2,2};
    Solution s;
    cout << s.MoreThanHalfNum_Solution(num) << endl;
}

