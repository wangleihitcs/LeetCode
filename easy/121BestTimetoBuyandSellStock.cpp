//
//  121BestTimetoBuyandSellStock.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/12/17.
//  Copyright © 2018 wanglei. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // 方法一、暴力枚举，时间复杂度O(n^2)，空间复杂度O(1), 356ms
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1) return 0;
        int result = 0;
        for(int i = 0; i < prices.size()-1; i++) {
            for(int j = i + 1; j < prices.size(); j++) {
                if(prices[j] - prices[i] > result) {
                    result = prices[j] - prices[i];
                }
            }
        }
        return result;
    }
    // 方法二、稍微改进暴力枚举，时间复杂度O(n^2)，空间复杂度O(1), 8ms
    int maxProfit2(vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1) return 0;
        int result = 0;
        for(int i = 0; i < prices.size()-1; i++) {
            for(int j = i + 1; j < prices.size(); j++) {
                if(prices[j] - prices[i] <= 0) break; //增加一个判断
                if(prices[j] - prices[i] > result) {
                    result = prices[j] - prices[i];
                }
            }
        }
        return result;
    }
    // 方法三、进一步改进暴力枚举，时间复杂度O(n^2)，空间复杂度O(1), 8ms
    int maxProfit3(vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1) return 0;
        int result = 0;
        int i = 0;
        while(i < prices.size()-1) {
            bool isGoto = false;
            for(int j = i + 1; j < prices.size(); j++) {
                if(prices[j] - prices[i] <= 0) {//如果发现某一天比i天价格更小，则跳到这一天。
                    i = j;
                    isGoto = true;
                    break;
                }
                if(prices[j] - prices[i] > result) {
                    result = prices[j] - prices[i];
                }
            }
            if(!isGoto) {
                i++;
            }
        }
        return result;
    }
    
    // 方法四、精妙解法，时间复杂度O(n)，空间复杂度O(1)，8ms
    int maxProfit4(vector<int>& prices) {
        int result = 0;
        int low_price = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < low_price) {
                low_price = prices[i];
            }
            if(prices[i] - low_price > result) {
                result = prices[i] - low_price;
            }
        }
        return result;
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    Solution so;
    cout << so.maxProfit3(prices) <<endl;
}
