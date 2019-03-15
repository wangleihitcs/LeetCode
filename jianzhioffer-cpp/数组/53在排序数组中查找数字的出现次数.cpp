//
//  56getNumberOfK.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/14.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、暴力遍历，时间复杂度O(n)，空间复杂度O(1)
    int GetNumberOfK(vector<int> data ,int k) {
        int res = 0;
        for(int i = 0; i < data.size(); i++) {
            if(data[i] == k)
                res++;
        }
        return res;
    }
    
    //方法二、双指针，时间复杂度O(logn)，空间复杂度O(1)
    int GetNumberOfK2(vector<int> data ,int k) {
        int left = my_lower_bound(data, k);
        int right = my_lower_bound(data, k+1);
        
        return right - left;
    }
    int my_lower_bound(vector<int>& data, int k) {//O(logn)
        int left = 0, right = data.size()-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if(data[mid] < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main() {
    vector<int> data = {1,2,3,4,4,4,4,6,7,8};
    Solution s;
    cout << s.GetNumberOfK2(data, 4) << endl;
}
