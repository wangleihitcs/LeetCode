//
//  98ValidateBinarySearchTree.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/23.
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
    //方法一、递归，时间复杂度O(2^n)，空间复杂度O(1)，20ms，20.6MB
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        bool isOK = isValidBSTLeft(root ->left, root ->val) && isValidBSTRight(root ->right, root ->val);
        if(isOK) {
            return isValidBST(root ->left) && isValidBST(root ->right);
        }
        return false;
    }
    bool isValidBSTLeft(TreeNode* root, int target) {
        if(root == NULL) return true;
        if(root ->val < target) {
            bool isLeftOK = isValidBSTLeft(root ->left, target);
            bool isRightOK = isValidBSTLeft(root ->right, target);
            return isLeftOK && isRightOK;
        }
        return false;
    }
    bool isValidBSTRight(TreeNode* root, int target) {
        if(root == NULL) return true;
        if(root ->val > target) {
            bool isLeftOK = isValidBSTRight(root ->left, target);
            bool isRightOK = isValidBSTRight(root ->right, target);
            return isLeftOK && isRightOK;
        }
        return false;
    }
    
    //方法二、递归，时间复杂度O(n)，空间复杂度O(n)，20ms，20.6MB
    bool isValidBST2(TreeNode* root) {
        if(root == NULL) return true;
        return isValidBSTCore(root, NULL, NULL);
    }
    bool isValidBSTCore(TreeNode* root, TreeNode* lower_limit, TreeNode* upper_limit) {
        if(lower_limit != NULL && root ->val <= lower_limit ->val) {
            return false;
        }
        if(upper_limit != NULL && root ->val >= upper_limit ->val) {
            return false;
        }
        bool left = root ->left == NULL ? true : isValidBSTCore(root ->left, lower_limit, root);
        bool right = root ->right == NULL ? true : isValidBSTCore(root ->right, root, upper_limit);
        return left && right;
    }
};
