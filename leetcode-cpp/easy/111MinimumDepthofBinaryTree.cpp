//
//  111MinimumDepthofBinaryTree.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/12/6.
//  Copyright © 2018 wanglei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 方法一、暴力递归
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        int left_depth = minDepth(root ->left);
        int right_depth = minDepth(root ->right);
        if(left_depth == 0 && right_depth == 0) return 1;
        if(left_depth == 0) return right_depth + 1;
        if(right_depth == 0) return left_depth + 1;
        int min = left_depth <= right_depth ? left_depth : right_depth;
        if(left_depth != 0 && right_depth != 0) return min + 1;
    }
    
};
