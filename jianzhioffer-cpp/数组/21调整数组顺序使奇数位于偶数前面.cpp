//
//  21reOrderArray.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/3.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、借助数组，时间复杂度O(n)，空间复杂度O(n)，4ms
    //要求奇数在偶数前面而且奇数对奇数和偶数对偶数的相对位置不变
    //遍历了3n次
    void reOrderArray(vector<int>& array) {
        vector<int> odd, even;
        for(int i = 0; i < array.size(); i++) {
            if(array[i] % 2 == 0) even.push_back(array[i]);
            else
                odd.push_back(array[i]);
        }
        for(int i = 0; i < odd.size(); i++)
            array[i] = odd[i];
        for(int i = odd.size(); i < odd.size()+even.size(); i++)
            array[i] = even[i-odd.size()];
    }
    
    //方法二、双指针，时间复杂度O(n)，空间复杂度O(1)
    //前提是只要求奇数在偶数前面
    void reOrderArray2(vector<int>& array) {
        int left = 0, right = array.size()-1;
        while (left < right) {
            while(left < right && array[left] % 2 != 0)
                left++;
            while(left < right && array[right] % 2 == 0)
                right--;
            if(left < right) {
                int temp = array[left];
                array[left] = array[right];
                array[right] = temp;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> array = {1,2,3,4,5,6,8,7,9,10,11};
    s.reOrderArray2(array);
    
    for(int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
