//
//  110BalancedBinaryTree.cpp
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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        
        int diff = abs(maxDepth(root ->left) - maxDepth(root ->right));
        if(diff > 1) return false;
        
        return isBalanced(root ->left) and isBalanced(root ->right);
    }
    
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        int left_depth = maxDepth(root ->left);
        int right_depth = maxDepth(root ->right);
        int max = left_depth > right_depth ? left_depth : right_depth;
        
        return max + 1;
    }
};
