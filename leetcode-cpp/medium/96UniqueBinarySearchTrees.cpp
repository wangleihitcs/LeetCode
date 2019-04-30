//
//  96UniqueBinarySearchTrees.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/22.
//  Copyright © 2019 wanglei. All rights reserved.
//


#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //方法一、dp，时间复杂度O(n^2)，空间复杂度O(n)，4ms，8.2MB
    //f[k] = f[k-1]*f[0] + f[k-2]*f[1] + ... + f[0]*f[k-1]
    int numTrees(int n) {
        vector<int> f;
        f.push_back(1);
        for(int k = 1; k <= n; k++) {
            int temp = 0;
            for(int j = 1; j <=k ; j++) {
                temp += f[k-j]*f[j-1];
            }
            f.push_back(temp);
        }
        return f[n];
    }
};
