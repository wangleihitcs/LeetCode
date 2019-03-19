//
//  66multiplyArray.cpp
//  JianzhiOffer
//
//  Created by 汪磊 on 2019/3/19.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一、暴力解法，时间复杂度O(n^2)，空间复杂度O(1)
    vector<int> multiply(const vector<int>& A) {
        vector<int> res;
        if(A.size() <= 1) return res;
        
        for(int i = 0; i < A.size(); i++) {
            int m = 1;
            for(int j = 0; j < A.size(); j++) {
                if(i != j) m *= A[j];
            }
            res.push_back(m);
        }
        return res;
    }
    //方法二、借助上三角和下三角，时间复杂度O(n)，空间复杂度O(1)
    vector<int> multiply2(const vector<int>& A) {
        vector<int> res;
        if(A.size() <= 1) return res;
        
        int temp = 1;
        res.push_back(temp);
        //求上三角
        for(int i = 1; i < A.size(); i++) {
            temp *= A[i-1];
            res.push_back(temp);
        }
        temp = 1;
        //求下三角
        for(int j = A.size() - 2; j >= 0; j--) {
            temp *= A[j+1];
            res[j] *= temp;
        }
        
        return res;
    }

};

int main() {
    vector<int> A = {1,2,3,4,5,6};
    Solution s;
    vector<int> res = s.multiply(A);
    for(auto r : res) {
        cout << r << " ";
    }
    cout << endl;
    res = s.multiply2(A);
    for(auto r : res) {
        cout << r << " ";
    }
    cout << endl;
}
