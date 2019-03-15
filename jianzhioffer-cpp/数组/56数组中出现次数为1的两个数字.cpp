//
//  56findNumsAppearOnce.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/15.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    //方法一、暴力枚举，时间复杂度O(n)，空间复杂度O(k)，k为不重复数字个数
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() < 2) return;
        map<int, int> m;
        for(int i = 0; i < data.size(); i++) {
            if(m.find(data[i]) == m.end()) {
                m.insert(pair<int, int>(data[i], 1));
            } else {
                m[data[i]]++;
            }
        }
        map<int, int>::iterator it;
        int flag = 0;
        for(it = m.begin(); it != m.end(); it++) {
            if(it ->second == 1 && flag == 0) {
                *num1 = it ->first;
                flag++;
            } else if(it ->second == 1 && flag == 1) {
                *num2 = it ->first;
            }
        }
    }
    
    //方法二、异或运算，时间复杂度O(n)，空间复杂度O(1)
    void FindNumsAppearOnce2(vector<int> data,int* num1,int *num2) {
        if(data.size() < 2) return;

        int oR = 0;
        for(int i = 0; i < data.size(); i++) {
            oR ^= data[i];
        }
        
        unsigned int indexOf1 = FindFirstBits1(oR);
        *num1 = 0;
        *num2 = 0;
        for(int j = 0; j < data.size(); j++) {
            if(isBit1(data[j], indexOf1)) {
                *num1 ^= data[j];
            } else {
                *num2 ^= data[j];
            }
        }
        
    }
    unsigned int FindFirstBits1(int num) {
        int indexBit = 0;
        while(((num & 1) == 0) && (indexBit < 8 * sizeof(int))) {
            num = num >> 1;
            ++indexBit;
        }
        return indexBit;
    }
    bool isBit1(int num, unsigned int indexBit) {
        num = num >> indexBit;
        return (num & 1);
    }
};

int main() {
    int* num1 = (int *)malloc(sizeof(int));
    int* num2 = (int *)malloc(sizeof(int));
    vector<int> data = {1,1,2,3,4,4,4,4,5,5,6,6};
    
    Solution s;
    s.FindNumsAppearOnce2(data, num1, num2);
    cout << *num1 << " " << *num2 << endl;
}
