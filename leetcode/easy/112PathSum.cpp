//
//  112PathSum.cpp
//  LeetCode
//
//  Created by 汪磊 on 2018/12/10.
//  Copyright © 2018 wanglei. All rights reserved.
//

#include <iostream>
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        if(root ->left == NULL && root ->right == NULL && root ->val == sum) return true;
        if(root ->left == NULL && root ->right == NULL && root ->val != sum) return false;
        if(root ->left == NULL && root ->right != NULL) {
            return hasPathSum(root ->right, sum - root ->val);
        }
        if(root ->left != NULL && root ->right == NULL) {
            return hasPathSum(root ->left, sum - root ->val);
        }
        else {
            bool isLeftOK = hasPathSum(root ->left, sum-root ->val);
            bool isRightOK = hasPathSum(root ->right, sum-root ->val);
            return isLeftOK || isRightOK;
        }
    }
    
    // 方法二、精简递归
    bool hasPathSum1(TreeNode* root, int sum) {
        if(root == NULL) return false;
        if(root ->left == NULL && root ->right == NULL && root ->val == sum) return true;
        if(root ->left == NULL && root ->right == NULL && root ->val != sum) return false;
        
        bool isLeftOK = hasPathSum(root ->left, sum-root ->val);
        bool isRightOK = hasPathSum(root ->right, sum-root ->val);
        
        return isLeftOK || isRightOK;
    }
    
};
