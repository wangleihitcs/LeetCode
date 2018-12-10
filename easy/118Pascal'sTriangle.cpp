//
//  118Pascal'sTriangle.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/12/10.
//  Copyright © 2018 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows == 0) return result;
        vector<int> v1 = {1};
        result.push_back(v1);
        if(numRows == 1) return result;
        vector<int> v2 = {1, 1};
        result.push_back(v2);
        if(numRows == 2) return result;
        
        for(int i = 1; i < numRows - 1; i++) {
            vector<int> temp = {1};
            for(int j = 0; j < result[i].size()-1; j++) {
                temp.push_back(result[i][j] + result[i][j+1]);
            }
            temp.push_back(1);
            result.push_back(temp);
        }
        
        return result;
    }
};

int main() {
    
}
