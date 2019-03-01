//
//  119.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/12/10.
//  Copyright © 2018 wanglei. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result = {1};
        if(rowIndex == 0) return result;
        result = {1, 1};
        if(rowIndex == 1) return result;
        
        vector<int> last_vector = result;
        for(int i = 1; i < rowIndex; i++) {
            vector<int> new_vector = {1};
            for(int j = 0; j < last_vector.size()-1; j++) {
                new_vector.push_back(last_vector[j] + last_vector[j+1]);
            }
            new_vector.push_back(1);
            last_vector = new_vector;
        }
        result = last_vector;
        return result;
    }
};
