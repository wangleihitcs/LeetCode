//
//  95UniqueBinarySearchTreesII.cpp
//  LeetCode
//
//  Created by 汪磊 on 2019/4/22.
//  Copyright © 2019 wanglei. All rights reserved.
//

#include <iostream>
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
    //方法一、递归，时间复杂度O(2^n)，空间复杂度O(2^n)，32ms，17.4MB
    vector<TreeNode*> generateTrees(int n) {
        if(n <= 0) return {};
        return generateTreesCore(1, n);
    }
    vector<TreeNode*> generateTreesCore(const int start, const int end) {
        if(start > end) {
            return {nullptr};
        }
        vector<TreeNode*> trees;
        for (int i = start; i <= end; i++){
            for (TreeNode* leftRoot : generateTreesCore(start, i - 1)){
                for (TreeNode* rightRoot : generateTreesCore(i + 1, end)) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
};
