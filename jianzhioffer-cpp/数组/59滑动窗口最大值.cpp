//
//  59maxInWindows.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/18.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    //方法一，暴力解法，时间复杂度O(nk)，空间复杂度O(1)
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> res;
        if(num.size() < size || size < 1) return res;
        
        for(int i = 0; i <= num.size() - size; i++) {
            int max = num[i];
            for(int j = i; j < i + size; j++) {
                if(num[j] > max) max = num[j];
            }
            res.push_back(max);
        }
        
        return res;
    }
    
    //方法二、借助双端队列，存储一个最大元素和若干个候选元素
    vector<int> maxInWindows2(const vector<int>& num, unsigned int size) {
        vector<int> res;
        if(num.size() < size || size < 1) return res;
        deque<int> index;
        for(int i = 0; i < size; i++) {
            //如果进来的元素大于队列中所有元素的值，则清空队列，插入该元素
            while(!index.empty() && num[i] >= num[index.back()]) {
                index.pop_back();
            }
            index.push_back(i);
        }
        for(int i = size; i < num.size(); i++) {
            res.push_back(num[index.front()]);
            while(!index.empty() && num[i] >= num[index.back()]) {
                index.pop_back();
            }
            //最大值离开滑动窗口
            if(!index.empty() && index.front() <= (i - size)) {
                index.pop_front();
            }
            index.push_back(i);
        }
        res.push_back(num[index.front()]);
        return res;
    }
};

int main() {
    vector<int> num = {2,3,4,2,6,2,5,1};
    Solution s;
    
    vector<int> res = s.maxInWindows2(num, 3);
    for(auto r : res)
        cout << r << " ";
    cout << endl;
}
