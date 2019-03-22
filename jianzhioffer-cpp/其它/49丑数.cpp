//
//  49isUgly.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/22.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、暴力枚举，时间复杂度太大，不通过
    int GetUglyNumber_Solution(int index) {
        if(index <= 0) return 0;
        int num = 0;
        int uglyCount = 0;
        while(uglyCount < index) {
            num++;
            if(isUgly(num)) uglyCount++;
        }
        return num;
    }
    bool isUgly(int num) {
        while(num % 2 == 0)
            num /= 2;
        while(num % 3 == 0)
            num /= 3;
        while(num % 5 == 0)
            num /= 5;
        return (num == 1) ? true : false;
    }
    
    //方法二、生成法
    int GetUglyNumber_Solution2(int index) {
        if(index <= 0) return 0;
        int* array = new int[index];
        array[0] = 1;
        int nextIndex = 1;
        
        int* index2 = array;
        int* index3 = array;
        int* index5 = array;
        
        while(nextIndex < index) {
            int min = Min(*index2 * 2, *index3 * 3, *index5 * 5);
            array[nextIndex] = min;
            
            while(*index2 * 2 <= array[nextIndex])
                index2++;
            while(*index3 * 3 <= array[nextIndex])
                index3++;
            while(*index5 * 5 <= array[nextIndex])
                index5++;
            
            nextIndex++;
        }
        
        return array[index - 1];
    }
    int Min(int num1, int num2, int num3) {
        int min12 = (num1 < num2) ? num1 : num2;
        return (min12 < num3) ? min12 : num3;
    }
    
    
};

int main() {
    Solution s;
    cout << s.GetUglyNumber_Solution2(8) << endl;
    return 0;
}

