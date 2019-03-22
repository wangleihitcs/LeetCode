//
//  61IsContinuous.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/21.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、理解题意
    bool IsContinuous(vector<int> numbers) {
        if(numbers.size() <= 0 || numbers.size() > 5) return false;
        
        //0.排序
        sort(numbers.begin(), numbers.end());
        
        //1.统计0的个数
        int num0 = 0;
        for(int i = 0; i < numbers.size(); i++) {
            if(numbers[i] == 0) num0++;
        }
        
        //2.统计间隔个数
        int numGap = 0;
        for(int i = num0; i < numbers.size()-1; i++) {
            if(numbers[i] == numbers[i+1]) {
                return false;
            }
            numGap += numbers[i+1] - numbers[i] - 1;
        }
        
        return (numGap > num0) ? false : true;
    }
};

int main() {
    vector<int> num = {0, 1, 3, 4, 5};
    Solution s;
    cout << s.IsContinuous(num) << endl;
}
