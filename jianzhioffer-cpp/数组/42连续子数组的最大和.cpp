//
//  42findGreatestSumOfSubArray.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/4.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include "iostream"
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、暴力枚举，时间复杂度O(n^3)，空间复杂度O(1)，3ms
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() == 0) return 0;
        int max = array[0];
        for(int i = 0; i < array.size(); i++) {
            for(int j = i; j < array.size(); j++) {
                int temp = 0;
                for(int k = i; k <= j; k++) {
                    temp += array[k];
                }
                if(temp > max) {
                    max = temp;
                }
            }
        }
        return max;
    }
    
    //方法二、常识找规律，时间复杂度O(n)，空间复杂度O(1)
    int FindGreatestSumOfSubArray2(vector<int> array) {
        if(array.size() == 0) return 0;
        int max = array[0], temp = 0;
        for(int i = 0; i < array.size(); i++) {
            temp += array[i];
            if(temp > max) {
                max = temp;
            }
            if(temp < 0) {
                temp = 0;
                continue;
            }
            
        }
        return max;
    }
    
};

int main() {
    vector<int> array = {-6,-3,-2,7,-15,-1,2,2};
    Solution s;
    cout << s.FindGreatestSumOfSubArray2(array) << endl;
}
