//
//  226InvertBinaryTree.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/5/30.
//  Copyright © 2019 wanglei. All rights reserved.
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
    //方法一、递归，时间复杂度O(n)，空间复杂度O(h)，4ms，9.4MB
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        invertTreeCore(root);
        return root;
    }
    void invertTreeCore(TreeNode* root) {
        if(root ->left == NULL && root ->right == NULL) return;
        TreeNode* temp = root ->left;
        root ->left = root ->right;
        root ->right = temp;
        if(root ->left != NULL) invertTreeCore(root ->left);
        if(root ->right != NULL) invertTreeCore(root ->right);
    }
    
    //方法二、一的改进，时间复杂度O(n)，空间复杂度O(h)，0ms，9.2MB
    TreeNode* invertTree2(TreeNode* root) {
        if(root == NULL) return NULL;
        TreeNode* left = invertTree2(root ->left);
        TreeNode* right = invertTree2(root ->right);
        root ->left = right;
        root ->right = left;
        return root;
    }
};
