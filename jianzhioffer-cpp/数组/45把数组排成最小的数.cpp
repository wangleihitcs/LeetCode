//
//  45printMinNumber.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/6.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、
    //比较两个数字拼接起来的大小
    string PrintMinNumber(vector<int> numbers) {
        string s = "";
        if(numbers.size() == 0) return s;
        
        for(int i = 0; i < numbers.size()-1; i++) {
            for(int j = i+1; j < numbers.size(); j++) {
                if(compareAB(numbers[i], numbers[j]) > 0) {
                    int temp = numbers[i];
                    numbers[i] = numbers[j];
                    numbers[j] = temp;
                }
            }
        }
        
        for(int i = 0; i < numbers.size(); i++) {
            s += to_string(numbers[i]);
        }
        return s;
    }
    int compareAB(int a, int b) {
        string ab = to_string(a) + to_string(b);
        string ba = to_string(b) + to_string(a);
        return ab.compare(ba);
    }
};

int main() {
    Solution s;
    vector<int> v = {3,32,321,2,45,457,121};
    cout << s.PrintMinNumber(v) << endl;
    cout << s.compareAB(457, 2) << endl;
}
