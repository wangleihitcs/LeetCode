//
//  40getLeastNumbers.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/4.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    //方法一、排序，时间复杂度O(nlogn)，空间复杂度(n)，4ms
    vector<int> GetLeastNumbers(vector<int> input, int k) {
        vector<int> res;
        if(k <= 0 || input.size() <= 0 || k > input.size()) return res;
        
        sort(input.begin(), input.end());
        for(int i = 0; i < k; i++) {
            res.push_back(input[i]);
        }
        
        return res;
    }
    
    //方法二、时间复杂度O(nlogk)，空间复杂度O(k)，3ms
    vector<int> GetLeastNumbers2(vector<int> input, int k) {
        vector<int> res;
        if(k <= 0 || input.size() <= 0 || k > input.size()) return res;
        
        priority_queue<int> pq;
        for(int i = 0; i < input.size(); i++) {
            if(pq.size() < k) {
                pq.push(input[i]);
            } else {
                pq.push(input[i]);
                pq.pop();
            }
        }
        while(!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};

int main() {
    vector<int> input = {4,5,1,6,2,7,3,8};
    Solution s;
    vector<int> res = s.GetLeastNumbers2(input, 4);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}
