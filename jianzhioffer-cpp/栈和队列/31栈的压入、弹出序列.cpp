//
//  31isPopOrder.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/14.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    //方法一、构造辅助栈，时间复杂度O(n)，空间复杂度O(n)
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        int i = 0, j = 0;
        while(j <= popV.size()-1) {
            if(s.empty()) {
                s.push(pushV[i++]);
            }
            while(s.top() != popV[j] && i <= pushV.size()-1) {
                s.push(pushV[i++]);
            }
            if(s.top() == popV[j]) {
                s.pop();
            }
            j++;
        }
        if(s.empty()) return true;
        return false;
    }
};

int main() {
    vector<int> pushV = {1,2,3,4,5};
    vector<int> popV = {5,4,3,2,1};
    
    Solution s;
    cout << s.IsPopOrder(pushV, popV) << endl;
}
