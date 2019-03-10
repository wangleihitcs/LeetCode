//
//  51inversePairs.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/9.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、暴力解法，时间复杂度O(n^2)，空间复杂度O(1)，time limit7
    int InversePairs(vector<int> data) {
        int res = 0;
        for(int i = data.size()-1; i > 0; i--) {
            for(int j = i-1; j >= 0; j--) {
                if(data[j] > data[i]) {
                    res++;
                }
            }
        }
        return res % 1000000007;
    }
    
    //方法二、归并排序的分治思想，时间复杂度O(nlogn)，空间画复杂度O(n)，通过75%
    int InversePairs2(vector<int> data) {
        if(data.size() <= 1) return 0;
        
        vector<int> temp = data;
        long long count = InversePairsCore(data, temp, 0, data.size()-1);
        
        return count % 1000000007;
    }
    long long InversePairsCore(vector<int>& data, vector<int>& temp, int left, int right) {
        if(left > right) return 0;
        if(left == right) {
            temp[left] = data[left];
            return 0;
        }
        int mid = (left + right) / 2;
        long long leftCount = InversePairsCore(data, temp, left, mid);
        long long rightCount = InversePairsCore(data, temp, mid+1, right);
        
        int i = mid, j = right, count = 0;
        int index = right;
        while(i >= left && j >= mid+1) {
            if(data[i] > data[j]) {
                count += j - mid;
                temp[index--] = data[i--];
            } else {
                temp[index--] = data[j--];
            }
        }
        while(i >= left) {
            temp[index--] = data[i--];
        }
        while(j >= mid+1) {
            temp[index--] = data[j--];
        }
        
        for(int k = left; k <= right; k++) {
            data[k] = temp[k];
        }
        
        return leftCount + rightCount + count;
    }
    
};

int main() {
    vector<int> data = {7,5,6,4};
    Solution s;
    cout << s.InversePairs2(data) << endl;
}
