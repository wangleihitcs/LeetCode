//
//  3duplicate.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/18.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //方法一、暴力
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers == NULL || length <= 0) return false;
        
        for(int i = 0; i < length - 1; i++) {
            for(int j = i + 1; j < length; j++) {
                if(numbers[i] == numbers[j]) {
                    *duplication = numbers[i];
                    return true;
                }
            }
        }
        
        return false;
    }
    
    //方法二、哈希表，时间复杂度O(n)，因为建表需要便利一遍，空间复杂度O(n)
    bool duplicate2(int numbers[], int length, int* duplication) {
        if(numbers == NULL || length <= 0) return false;
        int hash_table[length];
        for(int i = 0; i < length; i++) {
            int m = numbers[i] % length;
            if(hash_table[m] == 0) {
                hash_table[m]++;
            } else {
                *duplication = numbers[i];
                return true;
            }
        }
        return false;
    }
};

int main() {
    int a[101] = {2,1,3,1};
    Solution s;
    int duplication = 101;
    cout << s.duplicate2(a, 4, &duplication) << endl;
    cout << duplication << endl;
}
