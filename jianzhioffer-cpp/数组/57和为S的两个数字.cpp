//
//  57twoSum.cpp
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
    //方法一、双指针，时间复杂度O(n)，空间复杂度O(1)
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        if(array.size() < 2) return res;
        
        int left = 0, right = array.size() - 1;
        int minMulti = array[right] * array[right];
        while(left < right) {
            int m = array[left] + array[right];
            if(m == sum) {
                if(array[left] * array[right] < minMulti) {
                    res = {array[left], array[right]};
                    minMulti = array[left] * array[right];
                }
                left++;
                right--;
            } else if(m < sum) {
                left++;
            } else {
                right--;
            }
        }
        
        return res;
    }
};

int main() {
    vector<int> array = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    Solution s;
    vector<int> res = s.FindNumbersWithSum(array, 21);
    for(auto data : res) {
        cout << data << " ";
    }
    cout << endl;
}
