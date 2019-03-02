//
//  11minNumInRotateArray.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/2.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、暴力枚举，时间复杂度O(n)，空间复杂度O(1)，28ms，504k
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0) return 0;
        int min = rotateArray[0];
        for(int i = 1; i < rotateArray.size(); i++) {
            if(rotateArray[i] < min) {
                min = rotateArray[i];
            }
        }
        return min;
    }
    
    //方法二、方法一的优化，时间复杂度O(n)，空间复杂度O(1)，35ms，632k
    int minNumberInRotateArray2(vector<int> rotateArray) {
        if(rotateArray.size() == 0) return 0;
        int min = rotateArray[0];
        for(int i = 1; i < rotateArray.size(); i++) {
            if(rotateArray[i-1] > rotateArray[i]) {
                min = rotateArray[i];
                break;
            }
        }
        return min;
    }
    
    //方法三、双指针类似于二分查找，时间复杂度O(logn)，空间复杂度O(1)，34ms，988k
    int minNumberInRotateArray3(vector<int> rotateArray) {
        if(rotateArray.size() == 0) return 0;
        int left = 0, right = rotateArray.size()-1;
        while(left < right) {
            if(right - left == 1) {
                return rotateArray[left] <= rotateArray[right] ? rotateArray[left] : rotateArray[right];
            }
            
            int mid = (left + right) / 2;
            //考虑到旋转数组与数组本事相等的情况
            if(rotateArray[left] <= rotateArray[mid] && rotateArray[mid] <= rotateArray[right]) {
                break;
            }
            
            //考虑到旋转数组相等画元素过多的情况
            if(rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid]) {
                return MinInOrder(rotateArray, left, right);
            }

            if(rotateArray[left] <= rotateArray[mid]) {
                left = mid;
            }
            if(rotateArray[mid] <= rotateArray[right]) {
                right = mid;
            }
        }
        return rotateArray[left];
    }
    int MinInOrder(vector<int>& rotateArray, int left, int right) {
        int min = rotateArray[left];
        for(int i = left + 1; i <= right; i++) {
            if(rotateArray[i] < min) {
                min = rotateArray[i];
            }
        }
        return min;
    }
    
};

int main() {
    vector<int> nums = {3};
    Solution s;
    cout << s.minNumberInRotateArray3(nums) << endl;
}
