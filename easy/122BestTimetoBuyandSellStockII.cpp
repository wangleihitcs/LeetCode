//
//  122BestTimetoBuyandSellStockII.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/2/22.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、暴力枚举，递归方法，时间复杂度O(n^n)，空间复杂度O(n)，time limit
    int maxProfit(vector<int>& prices) {
        return calculate(prices, 0);
    }
    //计算s天后买卖的收益，总收益为s天前的收益+s天后的收益
    int calculate(vector<int>& prices, int s) {
        if(s > prices.size()-1) return 0;
        
        int maxProfit = 0;
        for(int start = s; start < prices.size(); start++) {
            for(int i = start+1; i < prices.size(); i++) {
                if(prices[i] > prices[start]) {
                    int tempProfit = prices[i] - prices[start] + calculate(prices, i+1);
                    if(tempProfit > maxProfit) maxProfit = tempProfit;
                }
            }
        }
    
        return maxProfit;
    }
    
    //方法二、峰值峰谷，时间复杂度O(n)，空间复杂度O(1)，8ms
    int maxProfit1(vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1) return 0;
        int peak = prices[0];
        int valley = prices[0];
        int maxProfit = 0;
        int i = 0;
        
        while(i < prices.size()-1) {
            while(i < prices.size()-1 && prices[i] >= prices[i+1])
                i++;
            valley = prices[i];
            while (i < prices.size() - 1 && prices[i] <= prices[i+1])
                i++;
            peak = prices[i];
            maxProfit += peak - valley;
        }
        
        return maxProfit;
    }
    
    //方法三、只找峰值i即可，时间复杂度O(n)，空间复杂度O(1)，8ms
    int maxProfit2(vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1) return 0;
        int maxProfit = 0;
        
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i-1] <= prices[i]) maxProfit += prices[i] - prices[i-1];
        }
        
        return maxProfit;
    }
    
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution so;
    cout << so.maxProfit2(prices) << endl;
}
